// UI.cpp

#include <Gosu\Text.hpp>
#include <sstream>

#include "UI.hpp"
#include "GameWindow.hpp" 
#include "ZOrder.hpp"

UI::UI():
font_(GameWindow::instance()->graphics(), Gosu::defaultFontName(), 20),
x_(10),
y_(10),
score_(0)
{
}

void UI::update(double score)
{
	score_ = score;
}

void UI::draw()
{
	std::wstringstream score;
	score << L"Score: ";
	score << score_;
	font_.draw(score.str(), x_,y_ , Z_UI, 1, 1, Gosu::Color::YELLOW);
}

void UI::drawBigScore()
{
	std::wstringstream score;
	score << score_;
	font_.draw(score.str(), 225, 250, Z_UI, 4, 4, Gosu::Color::GREEN);
}