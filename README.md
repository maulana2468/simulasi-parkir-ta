# Parking Simulation

A Shop X has a car park which only allows parking of cars in a row (serial). The parking area can accommodate as many as 10 cars in normal size. For parking order, the manager sets the following rules:

- The car enters the North (rear) door and exits the South (front) door. Every car that enters is recorded with a police number. Cars are only allowed to enter if parking space is still available (only 10 cars parked).
- If the car that is at the front (on the southernmost side) is going to get out then the car can get out immediately. But if the car that is coming out is the car in the middle, then the car located in front of it (in the south) must be removed temporarily.
- After the car in question leaves, the car that was temporarily removed is put back in the parking lot in its original arrangement. So that the car that was originally at the front remains in its original position. The cars that are located to the North of the exit will follow behind it.

![SS1](https://github.com/maulana2468/simulasi-parkirTA/blob/main/Screenshot%202021-04-12%20134802.png)

In the illustration above, the last car to enter was car number 10 (B22INI), and the first car that entered was car number 1 (B10CBD). If car number 1 (B10CBD) is about to come out, then the car immediately leaves because it is at the end (the process in the linked list is DELETE LEFT). If car number 3 (B41UBL) is going out, the cars in front of it, namely B10CBD and B25UPN, must be removed first and placed in a temporary area. After car number 3 (B41UBL) exits, the B10CBD and B25UPN cars are returned to the parking area. The following is an illustration of the conditions after car number 3 was issued:

![SS2](https://github.com/maulana2468/simulasi-parkirTA/blob/main/Screenshot%202021-04-12%20134841.png)

By paying attention to the problem above, in fact this simulation is not only filled with queues (queue) but also contains a stack, that is, when a car in the middle is released, all the cars in the south are stacked (pushed) in the shelter previous. It is only after the car in question leaves that all cars in the temporary shelter are stopped again. This way all the cars will be in the same position as they were before a car was pulled out of the parking lot.
