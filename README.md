# Traffic_Control

Problem Identification and Statement

Design a software to control a system of traffic lights at an intersection. The software should simulate the behavior of traffic lights at an intersection. Cycle length and traffic flow information must be read from a file. Every specific duration (say 24 hours), the data must be read from the file, the green timings should be updated based on the latest traffic condition, and the control should proceed with the updated green timings.

Gathering Information
The system has the following components:

1.	Traffic semaphores (signal lights): these are standard semaphores with three lights: red, yellow, and green.

2.	Traffic sensors that are embedded in each lane near the intersection to record the traffic flow for all roads. The sensors save the traffic rate information into a file.


3.	the four traffic lights are represented as L1, L2, L3, and L4. The system operates as follows:

•	Traffic light (L1) is green for a duration calculated based on the traffic flow rate in road R1, the other traffic lights (L2, L3, and L4) are red.

•	b. L1 becomes yellow for X seconds (X being a constant value). The Department of Transportation's traffic manual recommends that yellow lights are between 3 and 6 seconds long. Other traffic lights (L2, L3, and L4) remain in red state.

•	c. Then, traffic light L2 becomes green for a duration calculated based on the traffic flow rate in road R2. Meanwhile, L1, L3, and L4 are red.

•	d. Traffic light L2 becomes yellow for X seconds (X being a constant value). Other traffic lights (L1, L3, and L4) remain in red state.

•	e. Then, traffic light L3 becomes green for a duration calculated based on the traffic flow rate in road R3. Meanwhile, traffic lights L1, L2, and L4 are red.

•	f. Traffic light L3 becomes yellow for X seconds (X being a constant value). Other traffic lights (L1, L2, and L4) remain in red state.

•	g. Then, traffic light L4 becomes green for a duration calculated based on the traffic flow rate in road R4. Meanwhile, traffic lights L1, L2, and L3 are red.

•	h. Traffic light L4 becomes yellow for X seconds (X being a constant value). Other traffic lights (L1, L2, and L3) remain in red state.
 
•	i. The next cycle starts with traffic light L1 becoming green again, and so on.

The green timing for each traffic light is proportional to the traffic flow rate reported for the same road, according to the following equation:
 

𝑑𝑖
𝑄𝑇   = 𝑄𝑖 × 𝐶

 
Where 𝑑𝑖 is the green time for the ith traffic light, 𝑄𝑖 represents the traffic flow (number of vehicles per hour) crossing the ith traffic light, 𝑄𝑇 represents the total traffic flow passing through the intersection, and 𝐶 represents the cycle length in seconds.
