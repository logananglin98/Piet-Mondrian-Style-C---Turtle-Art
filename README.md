# L6: Recursive Art

## Use randomness, recursion, and turtles to create art in the style of Piet Mondrian.
### Starter files have been provided for you in C++

### Author(s):
- Author of this program: Logan Anglin
- Author of lab and stubs: Jan Pearce, Berea College
- Author of the [C-Turtle](https://github.com/walkerje/C-Turtle) library: Jesse Walker-Schadler

# Implementation Prompts due with Milestone 2:

1. **SPLITTING**
*How many units wide or tall did you consider a
rectangle too small to split?*

Initially, the base width and height were the size of the window, 800 * 600, however, I halved these so the rectangles would
be smaller.

2. **NUMBER CALLS**
*While filling out the above rectangle in the Mondrian style
using the series of steps above,
is there anything you noticed that will change how many times the
recursive function gets called? Explain*

I added a global counter to see how many times the mondiran() function was called and got 89, 97, and 85. Smaller base cases 
change how many times the code is executed.

3. **EXTRA STEPS**
*Most design choices have advantages as well as disadvantages.
Given the above series of steps, are there any steps you 
felt were unnecessary given what other steps perform?*

I've actually ommitted the several of the else if selections because they seemed redundant. I could be wrong, but the code would
execute the same drawing a vertical and horizontal split from half the width and height of the outer-most shape, and doing the
same thing using a base case width and height if both of these are included.

4. **DISADVANTAGE**
*Describe and explain at least one disadvantage of using recursion to
generate Mondrian art.*

Recursion involves storing a lot of info in memory. I struggle to imagine doing this lab using loops instead of a recursive
function, but I would imagine it would use less resources.

5. **CHALLENGES IN BASIC ALGORITHM**
*What challengeS did you encounter in trying to achieve the 
basic algorithm? Explain.*

It took me several attempts to get a working version of the basic algorithm. I at first had calculations that were way more 
complicated than what is currently in the program, and I spent hours playing around with the calculations trying to get them to
draw rectangles of the right dimensions in the right locations. I eventually realized that using goTo() for each corner of the
rectangle instead of right(90) and forward(width/height) would make figuring out the math a lot easier. Once I implemented the 
series of goTo() statements, figuring out the math for the recursions was much easier.

# Customization Prompts due with Final Milestone:

6. **REQUIRED CUSTOMIZATIONS**
*What customizations did you make Mondrian art, and why did you choose it.*

I added some RGB random coloring that sticks to cool colors, specifically blues, purples, and greens. I also added code that 
randomizes the thickness of the lines and made the base case much smaller so the art is more intricate.

7. **PROCESS SUMMARY**
*Briefly summarize your design and implementation process,
including how much your initial design plan evolved,
the final results you achieved, and the amount of time you spent
as a programmer or programmers in accomplishing these results.
This should be one or at most two paragraphs.*

 I first started by having the turtle draw the outermost rectangle that remains the same regardless of the randomness within. I
 then spent a considerable amount of time making sure the first if case would draw 4 rectangles in the proper places and with the
 proper dimensions inside the outermost rectangle. I tried several different approaches to this, and ended up eventually finding
 out the correct math and using it in tandem with drawing rectangles using four calls of the goTo() method instead of the 
 forward(width/height) right(90) approach, which was way more complicated. Once this first set of four rectangles inside the 
 outermost rectangle was set up correctly, the rest of the initial attempt of making Mondrian art was much easier. For the 
 customization part, I simply made what I had originally more complicated with random RGB values and a smaller base case.
 This lab took (I think) about 8 hours of work.

8. **DESIGN CHALLENGES**
*Describe the primary conceptual challenges that you encountered
in trying to complete this lab and what might have made the
lab easier for you.*

The biggest challenge of this lab had nothing to do with recursion, but rather getting the code right so the rectangels would
be drawn to appropriate sizes and in the right places. Once I got this initial code in place, implementing the selection
statements and making the code work with just the rectangles and not the colors was a breeze.
The biggest challenge of the latter part of the code (milestone 3 customization) was figuring out how to use random hexadecimal values to pass into the 
fillcolor() methods so the colors would be somewhat random. This took some trial and error and I tried to consult the
documentation for the CTurtle library on GitHub, but the link to the documentation was not working and I could not find any
helpful info in the starting page. I was eventually able to consult Nega and he told me how to use RGB values instead of 
hexadecimal values in the fill_color. Then I had much trouble randomizing the hexadecimal numbers and passing them into the 
fillcolor() method.

9. **BIG O ANALYSIS**
*Please analyze the Big O of all of the methods of the MondrianArt class,
including constructors.
Hint: Given the random nature of this lab,
be sure you write about the worst case.*

Assuming the program always divides the rectaingles into 4, I think the worst case Big O would be O(n) = 4^n

10. **TESTING**
*Please briefly describe your testing process.
Here you should be careful to select representative input cases,
including both representative typical cases as well as extreme cases.*

This program was not too hard to test considering there are no user inputs; it simply does everything it will do when clicking
run. Most of the testing was done by seeing if the program would do a full run by completely filling the 800x600 window, and if 
that full run looks like it should, meaning no rectangles are overlapping, and no blank spaces exist.

11. **ERRORS**
*List in bulleted form of all known errors
and deficiencies with a very brief explanation.*

- I do not think there are any errors.

12. **LEARNING AND REACTION**
*A paragraph or so of your own comments
on what you learned and your reactions to this lab.*

I have fully implemented recursion into a program. I already had a somewhat well understanding of recursion from past programming
courses, but this visualized the fact that the "smallest" case of recursion above the base case executes before outer cases of 
recursion.
My favorite part of this lab was the artistic element. I love visual art, but have never put that much effort into learning how
to create it myself. It's cool to see how I can use my CS skills to create art.

13. **INTEGRITY STATEMENT**
*INTEGRITY STATEMENT: Please briefly describe ALL help you 
received and all help you gave to others in completing this lab.
Also list all other references. 
If you worked in a pair you must also attested to only 
having worked together as a pair, not separately.*

I recieved some help from Nega on this project at work regarding the RGB values. I also recieved help from a TA in the Lab. I 
can't remember his name, but I think he was the TA for Theory of Computation if I remember correltly. As always, the initial code
created by the CS department faculty was very helpful. 

14. **Pairwork statement**
If you worked in a pair of programmers, you are required 
to use good pair programming practices, always working 
together and not using a divide and conquer technique 
in which only one of you does the work and learns. 
Also, the two programmers roles should be switched 
frequently--around every 20 minutes or so. 
If you worked alone, please say so. If you worked in a pair, 
please describe how you worked together.

I worked alone.

## References:
- This repo contains code by Jan Pearce and Jesse Walker-Schadler as described above.
- The linked lab heavily leverages nifty.stanford.edu/2018/stephenson-mondrian-art/
- https://www.rapidtables.com/web/color/RGB_Color.html
- https://github.com/walkerje/C-Turtle
