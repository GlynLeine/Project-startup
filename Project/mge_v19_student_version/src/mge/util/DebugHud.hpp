#ifndef DEBUGHUD_HPP
#define DEBUGHUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "mge/core/AbstractGame.hpp"

class Line : public sf::Drawable
{
public:
	Line()
	{

	}

	Line(const sf::Vector2f& point1, const sf::Vector2f& point2, sf::Color color = sf::Color::Yellow, float thickness = 0.5f) :
		color(color), thickness(thickness)
	{
		points[0] = point1;
		points[1] = point2;
		GenerateShape();
	}

	void SetPoints(const sf::Vector2f& point1, const sf::Vector2f& point2)
	{
		points[0] = point1;
		points[1] = point2;
		GenerateShape();
	}

	sf::Vector2f* GetPoints()
	{
		return points;
	}

	float GetThickness() { return thickness; }

	void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(vertices, 4, sf::Quads);
	}


private:
	void GenerateShape()
	{
		sf::Vector2f direction = points[1] - points[0];
		sf::Vector2f unitDirection = direction / std::sqrt(direction.x*direction.x + direction.y*direction.y);
		sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

		sf::Vector2f offset = (thickness / 2.f)*unitPerpendicular;

		vertices[0].position = points[0] + offset;
		vertices[1].position = points[1] + offset;
		vertices[2].position = points[1] - offset;
		vertices[3].position = points[0] - offset;

		for (int i = 0; i < 4; ++i)
			vertices[i].color = color;
	}

	sf::Vector2f points[2];

	sf::Vertex vertices[4];
	float thickness;
	sf::Color color;
};

/**
 * Very simple class capable of rendering a simple piece of text through SFML.
 */
class DebugHud
{
	public:
		DebugHud(AbstractGame* aGame );
		virtual ~DebugHud();
		void draw();

		void setDebugInfo (std::string pInfo);

		void appendFrameTime(float frameTime);
		void setFrameTimeChartPostion(sf::Vector2f pos);
		void setFrameTimeChartSize(sf::Vector2f size);


	private:
		AbstractGame* game;

        std::string _debugInfo;

        sf::Font _font;
        sf::Text _debugText;

		Line frametimeChart[120];
		sf::Vector2f frametimeChartPosition;
		sf::Vector2f frametimeChartScale;

        void _createDebugHud();

        DebugHud(const DebugHud&);
        DebugHud& operator=(const DebugHud&);

};

#endif // DEBUGHUD_HPP
