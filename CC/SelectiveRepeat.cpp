/* This code is contributed by Sourajita Dewasi. In Selective Repeat Protocol, there is a window in sender's sideand a same sized receiver buffer.
So if out of order packet arrives it's not taken in, if it's required in the receiver's buffer. 
There is independent acknowledgement. And for a lost data packet or acknowledgement slectively that data 
packet is retransmitted.*/ 

/*We are assuming the window size =4. both at sender and receiver's side. 
There might be different order of transmission but the no of retransmissions are same.
The order of transmission will depend upon the acknowledgement timer and Timeout timer*/


#include<iostream>

 int tmp1, tmp2, tmp3, tmp4, tmp5, i, windowsize = 4, noofPacket, morePacket;
 
using namespace std;
int main()
{
   
    char c;
    int receiver(int);
    int simulate(int);
    int negack(int);
    
    for(int i = 0;i < 10;i++)
        rand();
        noofPacket = rand()%10;
    cout<<"Number of frames is: "<<noofPacket;
    morePacket = noofPacket;
    
    while(morePacket >= 0)
    {
        tmp1 = simulate(windowsize);
        windowsize -= tmp1;
        tmp4 += tmp1;
        
        if(tmp4 > noofPacket)
            tmp4 = noofPacket;
            
        for(i = noofPacket - morePacket; i <= tmp4; i++)
       cout<<"\nSending Frame "<<i;
            
        tmp2 = receiver(tmp1);
        tmp3 += tmp2;
        
        if(tmp3 > noofPacket)
           tmp3 = noofPacket;
           
        tmp2 = negack(tmp1);
        tmp5 += tmp2;
        
        if(tmp5 != 0)
        {
           cout<<"\nNo acknowledgement for the frame "<<tmp5;
           cout<<"\nRetransmitting frame "<<tmp5;
        }
        morePacket -= tmp1;
        
        if(windowsize <= 0)
           windowsize = 4;
    }
    cout<<"\n Selective Repeat Protocol Ends. All packets are successfully transmitted.";
}

int receiver(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
        i = rand() % tmp1;
        return i;
}

int negack(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
        i = rand() % tmp1;
        return i;
}

int simulate(int windowsize)
{
    int tmp1, i;
    for(i = 0;i < 5;i++)
        tmp1 = rand();
    if(tmp1 == 0)
        tmp1 = simulate(windowsize);
        i = tmp1 % windowsize;
    if(i == 0)
        return windowsize;
    else
        return tmp1 % windowsize;
}






The given code simulates the Selective Repeat ARQ (Automatic Repeat reQuest) protocol, which is used in networking to ensure reliable data transmission. The program aims to simulate sending a certain number of frames and handling the acknowledgment and retransmission of frames when necessary. Here's a detailed explanation of the code:

Code Breakdown
Global Variables Initialization

cpp
Copy code
int tmp1, tmp2, tmp3, tmp4, tmp5, i, windowsize = 4, noofPacket, morePacket;
tmp1, tmp2, tmp3, tmp4, tmp5, i: Temporary variables used in the simulation.
windowsize: The size of the window (set to 4 initially).
noofPacket: The total number of packets/frames to be sent.
morePacket: The remaining number of packets/frames to be sent.
Function Prototypes

cpp
Copy code
int receiver(int);
int simulate(int);
int negack(int);
receiver(int): Simulates the reception of frames.
simulate(int): Simulates the process of sending frames.
negack(int): Simulates the reception of negative acknowledgments (NACKs).
Main Function

cpp
Copy code
int main()
{
    char c;
    ...
    for(int i = 0;i < 10;i++)
        rand();
    noofPacket = rand() % 10;
    cout<<"Number of frames is: "<<noofPacket;
    morePacket = noofPacket;
Randomly determines the number of frames to be sent.
Initializes morePacket with noofPacket.
Simulation Loop

cpp
Copy code
while(morePacket >= 0)
{
    tmp1 = simulate(windowsize);
    windowsize -= tmp1;
    tmp4 += tmp1;
    
    if(tmp4 > noofPacket)
        tmp4 = noofPacket;
        
    for(i = noofPacket - morePacket; i <= tmp4; i++)
        cout<<"\nSending Frame "<<i;
         
    tmp2 = receiver(tmp1);
    tmp3 += tmp2;
    
    if(tmp3 > noofPacket)
        tmp3 = noofPacket;
        
    tmp2 = negack(tmp1);
    tmp5 += tmp2;
    
    if(tmp5 != 0)
    {
        cout<<"\nNo acknowledgement for the frame "<<tmp5;
        cout<<"\nRetransmitting frame "<<tmp5;
    }
    morePacket -= tmp1;
    
    if(windowsize <= 0)
        windowsize = 4;
}
cout<<"\n Selective Repeat Protocol Ends. All packets are successfully transmitted.";
simulate(windowsize): Simulates the sending of frames within the current window size.
Updates the windowsize and the number of successfully sent frames (tmp4).
Sends frames and prints which frames are being sent.
receiver(tmp1): Simulates the reception of frames and updates the number of received frames (tmp3).
negack(tmp1): Simulates the reception of negative acknowledgments (NACKs).
If there is any NACK, the corresponding frame is retransmitted.
Decrements morePacket by the number of frames just attempted to send.
Resets the windowsize if it becomes zero or negative.
Helper Functions
Receiver Function

cpp
Copy code
int receiver(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
    i = rand() % tmp1;
    return i;
}
Simulates the reception process, using random values to determine how many frames are received successfully.
Negative Acknowledgment Function

cpp
Copy code
int negack(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
    i = rand() % tmp1;
    return i;
}
Simulates the generation of NACKs using random values to determine how many frames are not acknowledged.
Simulate Function

cpp
Copy code
int simulate(int windowsize)
{
    int tmp1, i;
    for(i = 0;i < 5;i++)
        tmp1 = rand();
    if(tmp1 == 0)
        tmp1 = simulate(windowsize);
    i = tmp1 % windowsize;
    if(i == 0)
        return windowsize;
    else
        return tmp1 % windowsize;
}
Simulates the process of determining how many frames can be sent in the current window size using random values.
Summary
The code is a simplified simulation of the Selective Repeat ARQ protocol. It randomly generates the number of frames, simulates sending them, handling acknowledgments, and retransmitting any frames that were not acknowledged. The use of random values helps mimic the unpredictability of real-world network conditions.





