#include <iostream>
#include <sstream>

#include "AbstractGame.hpp"
#include "mge/core/rendering/Renderer.hpp"
#include "mge/core/World.hpp"
#include "mge/core/rendering/Camera.hpp"
#include <SFML/Window/Mouse.hpp>
#include "glm.hpp"
#include "mge/config.hpp"

sf::Vector2f AbstractGame::mouseDelta = sf::Vector2f();
int AbstractGame::mouseWheelDir = 0;
std::string AbstractGame::contextInfo = "";

AbstractGame::AbstractGame(bool fullscreen, unsigned width, unsigned height) : fullscreen(fullscreen), resWidth(width), resHeight(height), _window(NULL), _renderer(NULL), _world(NULL), _fps(0)
{
	//ctor
}

AbstractGame::~AbstractGame()
{
	//dtor
	delete _window;
	delete _renderer;
	delete _world;
}

void AbstractGame::initialize() {
	std::cout << "Initializing engine..." << std::endl << std::endl;
	_initializeWindow();
	_printVersionInfo();
	_initializeGlew();
	_initializeRenderer();
	_initializeWorld();
	_initializeScene();
	std::cout << std::endl << "Engine initialized." << std::endl << std::endl;
}

///SETUP

void AbstractGame::_initializeWindow() {
	std::cout << "Initializing window..." << std::endl;

	if (resWidth == 0 || resHeight == 0)
	{
		resWidth = sf::VideoMode::getDesktopMode().width;
		resHeight = sf::VideoMode::getDesktopMode().height;
	}

	if (_window == nullptr)
	{
		sf::VideoMode videoMode;
		if (fullscreen)
		{
			std::vector<sf::VideoMode> fullscreenModes = sf::VideoMode::getFullscreenModes();
			for (unsigned i = 0; i < fullscreenModes.size(); i++)
			{
				if (fullscreenModes[i].width + fullscreenModes[i].height + ((float)fullscreenModes[i].width / fullscreenModes[i].height) >= resWidth + resHeight + ((float)resWidth / resHeight))
					videoMode = fullscreenModes[i];
				else
					break;
			}
			resWidth = videoMode.width;
			resHeight = videoMode.height;
		}
		else
		{
			videoMode = sf::VideoMode(resWidth, resHeight);
		}

		_window = new sf::RenderWindow(videoMode, "My Game!", fullscreen ? sf::Style::Fullscreen : sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3));
	}
	
	_window->setVerticalSyncEnabled(config::VSYNC_ENABLED);
	_window->setMouseCursorVisible(config::CURSOR_ENABLED);

	Camera::defProjectionMatrix = glm::perspective(glm::radians(90.0f), (float)resWidth / resHeight, 0.1f, 1000.0f);

	std::cout << "Window initialized with mode:" << std::endl;
	std::cout << "	width:		" << resWidth << std::endl;
	std::cout << "	height:		" << resHeight << std::endl;
	std::cout << "	fullscreen:	" << (fullscreen ? "true" : "false") << std::endl;
	std::cout << std::endl;
}

void AbstractGame::_printVersionInfo() {
	std::stringstream ss;

	ss << "Context info:" << std::endl;
	ss << "----------------------------------" << std::endl;
	//print some debug stats for whoever cares
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	//nice consistency here in the way OpenGl retrieves values
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	ss << "GL Vendor                  :	" << vendor << std::endl;
	ss << "GL Renderer              :	" << renderer << std::endl;
	ss << "GL Version (string)    :	" << version << std::endl;
	ss << "GL Version (integer) :	" << major << '.' << minor << std::endl;
	ss << "GLSL Version            :	" << glslVersion << std::endl;

	ss << "----------------------------------" << std::endl;

	contextInfo = ss.str();

	std::cout << contextInfo << std::endl;
}

void AbstractGame::_initializeGlew() {
	std::cout << "Initializing GLEW..." << std::endl;
	//initialize the opengl extension wrangler
	GLint glewStatus = glewInit();
	if (glewStatus != GLEW_OK)
	{
		std::cout << "GLEW ERROR: " << glewGetErrorString(glewStatus) << std::endl << std::endl;
		return;
	}

	std::cout << "Initialized GLEW:" << glewGetString(GLEW_VERSION) << std::endl << std::endl;
}

void AbstractGame::_initializeRenderer() {
	//setup our own renderer
	std::cout << "Initializing renderer..." << std::endl;
	if (_renderer == nullptr)
		_renderer = new Renderer();

	_renderer->init();
	_renderer->setClearColor(0, 0, 0);
	_renderer->resetMaterials();

	std::cout << "Renderer done." << std::endl << std::endl;
}

void AbstractGame::_initializeWorld() {
	//setup the world
	std::cout << "Initializing world..." << std::endl;
	_world = new World();
	std::cout << "World initialized." << std::endl << std::endl;
}

///MAIN GAME LOOP

void AbstractGame::run()
{
	//setting to calculate fps
	sf::Clock frameClock;
	sf::Clock cpuClock;
	sf::Clock gpuClock;
	int frameCount = 0;
	float timeSinceLastFPSCalculation = 0;

	while (_window->isOpen()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float frameTime = frameClock.restart().asSeconds();

		cpuClock.restart();
		_update(frameTime);
		cpuTime = cpuClock.getElapsedTime().asSeconds();

		gpuClock.restart();
		_render();
		_window->display();
		gpuTime = gpuClock.getElapsedTime().asSeconds();

		//fps count is updated once every 1 second
		frameCount++;
		timeSinceLastFPSCalculation += frameTime;
		if (timeSinceLastFPSCalculation > 1) {
			_fps = frameCount / timeSinceLastFPSCalculation;
			//std::cout << "fps: " << _fps << std::endl;

			timeSinceLastFPSCalculation -= 1;
			frameCount = 0;
		}

		mouseDelta = sf::Vector2f(0, 0);
		mouseWheelDir = 0;

		//empty the event queue
		_processEvents();
	}
}

void AbstractGame::_update(float pStep) {
	_world->update(pStep);
}

void AbstractGame::_render() {
	_renderer->render(_world);
}

void AbstractGame::_processEvents()
{
	sf::Event event;
	bool exit = false;

	//we must empty the event queue
	while (_window->pollEvent(event)) {
		//give all system event listeners a chance to handle events
		//optionally to be implemented by you for example you could implement a
		//SystemEventDispatcher / SystemEventListener pair which allows Listeners to
		//register with the dispatcher and then do something like:
		//SystemEventDispatcher::dispatchEvent(event);

		switch (event.type) {
		case sf::Event::Closed:
			exit = true;
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				exit = true;
			}
			if (event.key.code == sf::Keyboard::F11)
			{
				setFullscreen(!fullscreen);
			}
			break;
		case sf::Event::Resized:
			//would be better to move this to the renderer
			//this version implements nonconstrained match viewport scaling
			glViewport(0, 0, event.size.width, event.size.height);
			break;
		case sf::Event::MouseMoved:
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*_window);
			mouseDelta += sf::Vector2f((float)mousePos.x / _window->getSize().x - 0.5f, (float)mousePos.y / _window->getSize().y - 0.5f) * 10.f;
			sf::Mouse::setPosition(sf::Vector2i(_window->getSize().x / 2, _window->getSize().y / 2), *_window);
		}
		break;
		case sf::Event::MouseWheelScrolled:
			mouseWheelDir = glm::sign(event.mouseWheel.x);
			break;
		default:
			break;
		}
	}

	if (exit) {
		_window->close();
	}
}

void AbstractGame::setResolution(unsigned width, unsigned height)
{
	if (resWidth == width && resHeight == height)
		return;

	resWidth = width;
	resHeight = height;

	if (_window != nullptr)
	{
		_window->close();
		delete _window;
		_window = nullptr;
	}

	_initializeWindow();
	_initializeGlew();
	_initializeRenderer();
}

void AbstractGame::setFullscreen(bool fullscreen)
{
	if (fullscreen == this->fullscreen)
		return;

	this->fullscreen = fullscreen;

	if (_window != nullptr)
	{
		_window->close();
		delete _window;
		_window = nullptr;
	}

	_initializeWindow();
	_initializeGlew();
	_initializeRenderer();
}

sf::RenderWindow * AbstractGame::getWindow()
{
	return _window;
}



