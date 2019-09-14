# make-a-thon-2019
Code for our shopper bot

/*
 * 
// --- Make-A-Thon Game Robot ---//
//--- Physics Anonymous, lousy coding by rrWilhelm ---//

 * Sits in loop, waiting for button presses. Button presses corrospond to items added to an array. 
 * If last button press is 'go' then starts running items from the array, divided in to either [forward] or [+/-][rotate] commands.
 * 
 * array items:
 *  0=no item added (default), also a stop bit
 *  1=move forward
 *  2=turn
 *  3=turn the other way
 * 
 * l298n controller info:
 *  H-Bridge format
 *  pins 1-2 mean A direction, LOW-HIGH=forward, HIGH-LOW=reverse
 *  pins 3-4 mean B direction, LOW-HIGH=forward, HIGH-LOW=reverse
 *  
 *  enable A/B = PWM signals for movement
 *  
 */

/* --- Variables to adjust --- */
* int moveSpeed = 50; // pwm, 0-255 where 255 is max
* int moveRunTime = 500; // adjust this to get distance. This is time in milliseconds.
* int rotateRunTime = 500; // adjust this to get your 90 degrees. This is time in milliseconds.
* int pauseBetween = 300; // satisfying pause between moves

/* --- Pinout --- */
* int pwmA = 9;
* int dir1A = 5;
* int dir2A = 6;
* int pwmB = 10;
* int dir1B = 7;
* int dir2B = 8;
* int buttonFWD = 4;
* int buttonLEFT = 3;
* int buttonRIGHT = 2;
* int buttonGO = 1;
