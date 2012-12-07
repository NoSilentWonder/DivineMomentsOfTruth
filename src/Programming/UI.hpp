// UI.hpp

#ifndef U_I_HPP_
#define U_I_HPP_

#include <Gosu\Font.hpp>

class UI
{
public:
	UI();
	void update(double score);
	void draw();
	void drawBigScore();
private:
	Gosu::Font font_;
	double x_, y_;
	double score_;
};

#endif // U_I_HPP_