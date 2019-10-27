/*
PRODDEC
Score board code for arduino nano
Here we have two seven segment-left seven segment and right seven segment
*/
int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

int l_pins[7]={2,3,4,5,6,7,8}; 
//declare the pins of the left 7 segment

int r_pins[7]={2,3,4,5,6,7,8};   
//declare the pins of the right 7 segment

void clear_data(); //function for clearing the screen.

void calculate(int); //functions for calculating the left and right digit of score board
void data_write(int,int);   //functions for writing left and right segment

int up_pin=9; //button pin for increment the score
int down_pin=10; //button pin for decrement the score
int read_down=0; //variable to read the state of the down button
int read_up=0;  //variable to read the state of the up button
int score=0; //variable to store the actual score
int l_score=0; //variable to store the first digit of score
int r_score=0;  //varible to store the second digit of score

void setup()
{
    pinMode(up_pin,INPUT);
    pinMode(down_pin,INPUT);

    //setting left pins as output
    for(int i=0;i<7;i++)
    {
        pinMode(l_pins[i],OUTPUT);
    }

    //setting right pins as output
    for(int i=0;i<7;i++)
    {
        pinMode(r_pins[i],OUTPUT);
    }


}
void loop()
{
    read_up=digitalRead(up_pin);
    read_down=digitalRead(down_pin);
    if (read_up==1)
    {   
        score+=1;
        read_up=0;
        calculate(score);
    }
    else if (read_down==1)
    {   
        score-=1;
        read_down=0;
        calculate(score);
    }

}

void calculate(int score)
{
    if (score<10)
    {
        r_score=score;
        l_score=0;
    }
    else
    {
        r_score=score % 10;
        l_score=score/10;
    }
    clear_data();
    data_write(l_score,r_score);

    
}

//function to clear the data on the segment
void clear_data()
{
    for (int j=0; j < 7; j++) 
    {
        digitalWrite(l_pins[j],0);
    }
 
    for (int j=0; j < 7; j++) 
    {
        digitalWrite(r_pins[j],0);
    }

}



void data_write(int left,int right) 
{
    for (int j=0; j < 7; j++) 
    {
        digitalWrite(l_pins[j], num_array[left][j]);
    }
 
    for (int j=0; j < 7; j++) 
    {
        digitalWrite(r_pins[j], num_array[right][j]);
    }
  
}
