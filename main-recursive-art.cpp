 /* Authors: 
    Python version of Sierpinski's triangle by Jan Pearce; Conversion to C++ by Jesse W. Walker
	C-Turtle by Jesse  W.  Walker, GetRandom by Jan Pearce

 */

#include "CTurtle.hpp"   //This brings in the CTurtle library for use
#include <iostream> //for input & output
#include <random> //needed for Getrandom
#include <chrono> //needed for Getrandom's seed
namespace ct = cturtle;  //This makes it possible to use the CTurtle commands using ct::
using namespace std;

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};

void mondrian(ct::Turtle& t,ct::Point inpoint = {- 400, 300}, int width = 800, int height = 600) {
    /**Uses a turtle object to create a design inspired by Piet Mondrian. This design consists of randomly drawn rectangles
    inside of outer randomly drawn rectangles, with colors, dimensions, and locations chosen randomly. The rectangles
    do not overlap but also have no gaps of empty space, so the rectangles are flush with one-another. The base_width and 
    base_height directly control how long the program will take to complete, so it may be beneficial to increase them to make 
    the program finish faster if desired.*/
    int base_width = 50;
    int base_height = 60;

    // Chooses a random split within the middle 90% of the top and left lines of the outer rectangle.
    Getrandom randomizes_from_x(width * 0.9);
    Getrandom randomizes_from_y(height * 0.9);
    int split_from_x = randomizes_from_x.roll() + (width * 0.05);
    int split_from_y = randomizes_from_y.roll() + (height * 0.05);
 
    if (width > base_width / 2 && height > base_height / 2) {
        // Creates four recursive calls to the mondiran function using the random splits if the width and height are at least
        // half the width and height of the outer rectangle.
        mondrian(t, inpoint, split_from_x, split_from_y);
        mondrian(t, { inpoint[0] + split_from_x, inpoint[1]}, width - split_from_x, split_from_y);
        mondrian(t, { inpoint[0], inpoint[1] - split_from_y }, split_from_x, height - split_from_y);
        mondrian(t, { inpoint[0] + split_from_x, inpoint[1] - split_from_y }, width - split_from_x, height - split_from_y);  
    }
    else if (width > base_width / 2) {
        // Creates two recursive calls to the mondiran function using the random splits if the width is at least
        // half the width of the outer rectangle.
        mondrian(t, inpoint, split_from_x, height);
        mondrian(t, { inpoint[0] + split_from_x, inpoint[1] }, width - split_from_x, height);
    }
    else if (height > base_height / 2) {
        // Creates two recursive calls to the mondiran function using the random splits if the height is at least
        // half the height of the outer rectangle.
        mondrian(t, inpoint, width, split_from_y);
        mondrian(t, { inpoint[0], inpoint[1] - split_from_y }, width, height - split_from_y);
    }
    else {
        // The following code draws the smallest rectangles with randomized colors depending on the location.
        
        // These lines of code correctly calculate where the corners of the rectangles will be located.
        int corner_math_x = inpoint[0] + width;
        int corner_math_y = inpoint[1] - height;
        ct::Point corners[] = { inpoint, {corner_math_x, inpoint[1]}, {corner_math_x, corner_math_y}, {inpoint[0], corner_math_y} };

        //Used to create random RGB values for the turtle library's fillcolor methods.
        int color_choice;
        Getrandom choose_color(256);

        // Randomizes the line width.
        Getrandom line_width(7);
        
        if ( inpoint[0] < 0 && inpoint[1] > 0 ) {
            // Controls the colors of the rectangles drawn in the top left corner of the window.
            
            // These lines create randomized shades of blue.
            color_choice = choose_color.roll() - 1;
            ct::Color color(10, 10, color_choice);

            // Draws the rectangle of the correct color.
            t.fillcolor(color);
            t.begin_fill();
            t.penup();
            t.goTo(corners[3]);
            t.pendown();       
            for (int i = 0; i < 3; i++) {
                t.width(line_width.roll());
                t.goTo(corners[i]);
                t.pendown();
            }
            t.goTo(corners[3]);
            t.penup();
            t.end_fill();
        } else if (inpoint[0] < 0) {
            // Controls the colors of the rectangles drawn in the bottom left corner of the window.

            // These lines create randomized shades of green.
            color_choice = choose_color.roll() - 1;
            ct::Color color(10, color_choice, 10);

            // Draws the rectangle of the correct color.
            t.fillcolor(color);
            t.begin_fill();
            t.penup();
            t.goTo(corners[3]);
            t.pendown();
            for (int i = 0; i < 3; i++) {
                t.width(line_width.roll());
                t.goTo(corners[i]);
                t.pendown();
            }
            t.goTo(corners[3]);
            t.penup();
            t.end_fill();
        }
        else if (inpoint[1] > 0) {
            // Controls the colors of the rectangles drawn in the top right corner of the window.

            // These lines create randomized shades of purple.
            color_choice = choose_color.roll() - 1;
            ct::Color color((color_choice / 2) + 127, 0, 255);

            // Draws the rectangle of the correct color.
            t.fillcolor(color);
            t.begin_fill();
            t.penup();
            t.goTo(corners[3]);
            t.pendown();
            for (int i = 0; i < 3; i++) {
                t.width(line_width.roll());
                t.goTo(corners[i]);
                t.pendown();
            }
            t.goTo(corners[3]);
            t.penup();
            t.end_fill();
        } 
        else {
            // Controls the colors of the rectangles drawn in the bottom right corner of the window.

            // These lines create randomized shades of cyan.
            color_choice = choose_color.roll() - 1;
            ct::Color color(10, color_choice, color_choice);

            // Draws the rectangle of the correct color.
            t.fillcolor(color);
            t.begin_fill();
            t.penup();
            t.goTo(corners[3]);
            t.pendown();
            for (int i = 0; i < 3; i++) {
                t.width(line_width.roll());
                t.goTo(corners[i]);
                t.pendown();
            }
            t.goTo(corners[3]);
            t.penup();
            t.end_fill();
        }
    }
}

int main() {
    ct::TurtleScreen scr; //makes screen
    ct::Turtle myTurtle(scr);  //makes Turtle

    mondrian(myTurtle);
    
    scr.exitonclick();  //exists graphics screen
    return 0;
}
