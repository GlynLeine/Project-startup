#include <cassert>
#include <iostream>

#include <GL/glew.h>
#include <SFML/Graphics/Text.hpp>
#include "mge/util/DebugHud.hpp"
#include "mge/config.hpp"
#include "glm.hpp"

DebugHud::DebugHud(AbstractGame * aGame ): game(aGame), _debugInfo(), _font(), _debugText(), frametimeChartPosition(sf::Vector2f(0.01f, 0.99f)), frametimeChartScale(sf::Vector2f(0.3f, 0.1f))
{
	assert (game != NULL );

    if (!_font.loadFromFile(config::MGE_FONT_PATH+ "arial.ttf")) {
        std::cout << "Could not load font, exiting..." << std::endl;
        return;
    }

    _createDebugHud();
}

DebugHud::~DebugHud()
{
	//dtor
}

void DebugHud::_createDebugHud() {
    _debugText.setString("");
    _debugText.setFont(_font);
	_debugText.setCharacterSize(16);
	_debugText.setFillColor(sf::Color::White);
}



void DebugHud::setDebugInfo(std::string pInfo) {
    _debugText.setString(pInfo);
	_debugText.setPosition(10, 10);
}

void DebugHud::appendFrameTime(float frameTime)
{
	for (int i = 1; i < 120; i++)
	{
		Line line = frametimeChart[i];
		sf::Vector2f* points = line.GetPoints();
		points[0].x += line.GetThickness();
		points[1].x += line.GetThickness();
		line.SetPoints(points[0], points[1]);
		frametimeChart[i - 1] = line;
	}

	float colorscale = (frameTime - 0.016f) * 60.f;
	float heightscale = frameTime * 60.f;

	sf::Vector2u windowSize = game->getWindow()->getSize();

	sf::Color color = sf::Color(255 * glm::clamp(colorscale, 0.f, 1.f), 255 * glm::clamp((1.f - colorscale), 0.f, 1.f), 0, 125);
	sf::Vector2f pos = sf::Vector2f(frametimeChartPosition.x * windowSize.x, frametimeChartPosition.y * windowSize.y);
	frametimeChart[119] = Line(pos, pos - sf::Vector2f(0, heightscale * frametimeChartScale.y * windowSize.y), color, frametimeChartScale.x * windowSize.x / 120.f);
}

void DebugHud::draw()
{
	//glDisable( GL_CULL_FACE );
	sf::RenderWindow* _window = game->getWindow();

	glActiveTexture(GL_TEXTURE0);
    _window->pushGLStates();
	for(int i = 0; i < 120; i++)
		_window->draw(frametimeChart[i]);
    _window->draw(_debugText);
	_window->popGLStates();
}
