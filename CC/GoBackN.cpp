#include <bits/stdc++.h>
#include <ctime>

#define ll long long int
using namespace std;

int main() {
    ll tf, N, tt = 0;
    srand(time(NULL));

    cout << "Enter the Total number of frames: ";
    cin >> tf;
    cout << "Enter the Window Size: ";
    cin >> N;

    ll i = 1;

    while (i <= tf) {
        int z = 0;
        for (int k = i; k < i + N && k <= tf; k++) {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;
        }
        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;
            if (!f) {
                cout << "Acknowledgment for Frame " << k << "..." << endl;
                z++;
            } else {
                cout << "Timeout!! Frame Number: " << k << " Not Received" << endl;
                cout << "Retransmitting Window..." << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }

    cout << "Total number of frames which were sent and resent are: " << tt << endl;
    return 0;
}




ure, let's go through the code step-by-step to understand how it implements the Cyclic Redundancy Check (CRC) algorithm for error detection:

cpp
Copy code
#include <iostream>
#include <cstring>

using namespace std;

char exor(char a, char b) {
    return (a == b) ? '0' : '1';
}
Headers and Namespace:

#include <iostream>: Includes the input-output stream library for standard I/O operations.
#include <cstring>: Includes the C string library for string manipulation functions like strlen.
using namespace std;: Allows usage of standard library names without prefixing them with std::.
XOR Function:

The function exor takes two characters ('0' or '1') and returns '0' if they are the same, otherwise returns '1'. This simulates the XOR operation.
cpp
Copy code
void crc(char data[], const char key[]) {
    int datalen = strlen(data);
    int keylen = strlen(key);
    int totlen = datalen + keylen - 1;
    
    // Append keylen-1 zeros to data
    for(int i = 0; i < keylen - 1; i++) {
        data[datalen + i] = '0';
    }
    data[totlen] = '\0';
    
    char temp[totlen];
    char rem[keylen];

    for(int i = 0; i < keylen; i++) {
        rem[i] = data[i];
    }

    for(int i = 0; i < datalen; i++) {
        for(int j = 0; j < keylen; j++) {
            temp[j] = rem[j];
        }

        if(rem[0] == '0') {
            for(int k = 0; k < keylen - 1; k++) {
                rem[k] = rem[k + 1];
            }
        } else {
            for(int k = 0; k < keylen - 1; k++) {
                rem[k] = exor(temp[k + 1], key[k + 1]);
            }
        }
        
        rem[keylen - 1] = data[keylen + i];
    }
    
    for(int i = 0; i < keylen - 1; i++) {
        data[datalen + i] = rem[i];
    }
    data[totlen] = '\0';
}
CRC Function:
Inputs:

data[]: The input data to be encoded.
key[]: The CRC key (divisor).
Step-by-Step:

Calculate the lengths of data and key.
Compute totlen, the total length of the modified data (original data length + key length - 1).
Append keylen - 1 zeros to the end of data to accommodate the CRC bits.
Initial Remainder Setup:

Copy the first keylen bits of data into rem.
Main Division Loop:

Perform bitwise division of data by key:
Copy rem to temp for processing.
Check the leading bit of rem:
If it is '0', shift rem left by one bit.
If it is '1', perform bitwise XOR between rem and key and shift.
Append the next bit of data to rem.
Final Remainder:

After the loop, the final rem contains the CRC remainder.
Append this remainder to the end of data.
cpp
Copy code
int main() {
    char key[20], data[20];
    cout << "Enter the data: ";
    cin >> data;
    cout << "\nEnter the key: ";
    cin >> key;
    crc(data, key);
    cout << "\nCRC code: " << data << endl;
    return 0;
}
Main Function:
Prompt the user to input data and key.
Call the crc function to compute the CRC code.
Output the resulting data with the appended CRC code.
Example
If the user inputs:

Data: 11010011101100
Key: 1011
The crc function will:

Append zeros: 11010011101100000
Perform bitwise division using 1011 as the divisor.
Calculate the remainder and append it to the original data, resulting in the final encoded data string with the CRC bits.
This implementation ensures that errors in transmission can be detected using the generated CRC code.