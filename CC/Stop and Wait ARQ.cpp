/* Stop and Wait Protocol: Sender sends one frame and wait for it's independent acknowledgement before sending
another one. 2 cases might occur:
1) Frame is lost so the acknowledgement doesn't come. Sender retransmits Frame.
2) Acknowledgement is lost. the sender retransmits frame. Seeing an already received frame, the receiver resends the acknowledgement and silently 
discards the duplicate packet. */

#include <iostream>
using namespace std;

struct Sender{
    int PacketNo;
    int Sent;
    int Acknowledged;
}S[6];

struct Receiver{
    int AcknowledgementNo;
    int Received;
    int AcknowledgementSent;
}R[6];

/* We are assuming the 4th data packet is lost and the acknowledgement of 6 data packet is also lost */
int i=0;

int main() {
    
    //Making the data packets at Sender side from 0 to 5
	for (i=0; i<6; i++){
	    S[i].Sent=0;
	    S[i].Acknowledged=0;
	    S[i].PacketNo=i;
	}
	
	//Making the data packets at Sender side from 1 to 6
	for (i=1; i<=6; i++){
	    R[i].AcknowledgementSent=0;
	    R[i].Received=0;
	    R[i].AcknowledgementNo=i;
	}
	
	int check4=0; int check6=0; //To study the cases of retransmission by manually causing data packet corruption
	
	//Sending and receiving the data packets
	for(i=0; i<3; i++){
	    cout<<"\n\n Next Transmission";
	    cout<<"\n Sending PacketNo "<<i<<" from Sender";
	    S[i].Sent=1;
	    cout<<"\n Propagation Delay";
	    if(i==4 && check4==0){
	        R[i].Received=0;
	        check4=1; i--;
	        cout<<"\n Data PacketNo "<<i<<" not received.";
	    }
	    else{
	        R[i].Received=1;
	        R[i].AcknowledgementSent=1;
	        cout<<"\n Sending AcknowledgementNo "<<i+1<<" to Sender";
	        cout<<"\n Propagation Delay";
	        if(i==5 && check6==0){
	            S[i].Acknowledged=0;
	            check6=1;i--;
	            cout<<"\n Acknowledgement for DataPacketNo"<< i <<" not received";
	        }
	        else{
	            S[i]. Acknowledged=1;
	            cout<<"\n Acknowledgement for PacketNo "<<i<<" Received";
	            
	        }
	        
	}}
	return 0;
}







The provided code simulates a simple communication between a sender and a receiver, where data packets are sent from the sender to the receiver, and acknowledgements are sent back from the receiver to the sender. The simulation assumes the loss of the 4th data packet and the loss of the acknowledgement for the 6th data packet.

Here's a step-by-step explanation of the code's working:

1. **Data Structures Initialization:**
    - Two structures are defined: `Sender` and `Receiver`, each with relevant attributes to store information about the packets and acknowledgements.
    - Two arrays, `S` and `R`, of these structures are created to store information for 6 packets.

2. **Initialization of Sender and Receiver Arrays:**
    - The `Sender` array `S` is initialized with `Sent` and `Acknowledged` set to 0, and `PacketNo` set from 0 to 5.
    - The `Receiver` array `R` is initialized with `AcknowledgementSent` and `Received` set to 0, and `AcknowledgementNo` set from 1 to 6.

3. **Variables for Packet Loss Simulation:**
    - Two variables, `check4` and `check6`, are used to simulate the loss of the 4th data packet and the acknowledgement for the 6th data packet, respectively.

4. **Sending and Receiving Packets:**
    - The main logic is in the for-loop, which runs for the first 3 packets (`i` ranges from 0 to 2).
    - For each packet, the following steps occur:
        - The packet is marked as sent.
        - A propagation delay is simulated.
        - If the packet number is 4 and `check4` is 0, the packet is marked as not received by the receiver. `check4` is set to 1, and `i` is decremented to retry sending the same packet.
        - If the packet is not lost, the receiver marks it as received and sends an acknowledgement.
        - Another propagation delay is simulated.
        - If the packet number is 5 and `check6` is 0, the acknowledgement is marked as not received by the sender. `check6` is set to 1, and `i` is decremented to retry receiving the same acknowledgement.
        - If the acknowledgement is not lost, the sender marks it as acknowledged.

5. **Output:**
    - The code prints the status of each transmission, indicating whether the packet was sent, received, and acknowledged, and noting any simulated packet or acknowledgement losses.

**Detailed Steps of Execution:**

- **Iteration 1 (i=0):**
    - Packet 0 is sent.
    - Packet 0 is received by the receiver.
    - Acknowledgement for Packet 1 is sent.
    - Acknowledgement for Packet 0 is received by the sender.

- **Iteration 2 (i=1):**
    - Packet 1 is sent.
    - Packet 1 is received by the receiver.
    - Acknowledgement for Packet 2 is sent.
    - Acknowledgement for Packet 1 is received by the sender.

- **Iteration 3 (i=2):**
    - Packet 2 is sent.
    - Packet 2 is received by the receiver.
    - Acknowledgement for Packet 3 is sent.
    - Acknowledgement for Packet 2 is received by the sender.

Note: The simulation conditions for losing the 4th packet and the 6th packet's acknowledgement are never triggered because the loop runs only for the first 3 packets (`i` from 0 to 2). To see the effects of these conditions, the loop should run for more iterations.

**Corrections and Improvements:**

1. **Array Indexing Issues:**
    - The receiver array `R` is indexed from 1 to 6, which will cause an out-of-bounds error for `R[i]` when `i=0`. The initialization loop should start from 0 instead of 1.
    - The condition `if(i==4 && check4==0)` will never be true in the given loop. Similarly, `if(i==5 && check6==0)` will also never be true.

2. **Loop Boundaries:**
    - To simulate packet losses correctly, the loop should iterate through all 6 packets (`i < 6`).

Here's a corrected version of the loop and initializations:

```cpp
int main() {
    
    // Making the data packets at Sender side from 0 to 5
    for (i = 0; i < 6; i++) {
        S[i].Sent = 0;
        S[i].Acknowledged = 0;
        S[i].PacketNo = i;
    }
    
    // Making the data packets at Receiver side from 0 to 5
    for (i = 0; i < 6; i++) {
        R[i].AcknowledgementSent = 0;
        R[i].Received = 0;
        R[i].AcknowledgementNo = i + 1;
    }
    
    int check4 = 0; 
    int check6 = 0; // To study the cases of retransmission by manually causing data packet corruption
    
    // Sending and receiving the data packets
    for (i = 0; i < 6; i++) {
        cout << "\n\n Next Transmission";
        cout << "\n Sending PacketNo " << i << " from Sender";
        S[i].Sent = 1;
        cout << "\n Propagation Delay";
        if (i == 4 && check4 == 0) {
            R[i].Received = 0;
            check4 = 1; 
            i--;
            cout << "\n Data PacketNo " << i << " not received.";
        } else {
            R[i].Received = 1;
            R[i].AcknowledgementSent = 1;
            cout << "\n Sending AcknowledgementNo " << i + 1 << " to Sender";
            cout << "\n Propagation Delay";
            if (i == 5 && check6 == 0) {
                S[i].Acknowledged = 0;
                check6 = 1;
                i--;
                cout << "\n Acknowledgement for DataPacketNo" << i << " not received";
            } else {
                S[i].Acknowledged = 1;
                cout << "\n Acknowledgement for PacketNo " << i << " Received";
            }
        }
    }
    return 0;
}
```

This version corrects the indexing issues and allows the loop to run through all packets to demonstrate the packet loss and retransmission scenarios.