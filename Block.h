#pragma once
#include <SFML/Graphics.hpp>

class Block : public sf::Drawable
{
public:
	Block();
	Block(float x, float y, float blocksize);
	void SetColor(sf::Color newcolor);
	~Block();
private:
	void InitBlock();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	float x, y;
	float size;
	float defaultsize = 10.00;
	sf::RectangleShape block;
	sf::Color fillcolor;
	sf::Color linecolor;
};

