# Sending-sensor-data-from-ESP32-to-AWS-DynamoDB-cloud-storage
## To create a thing in AWS IOT core  
### Step 1:  
![Web capture_30-6-2022_185558_ap-south-1 console aws amazon com](https://user-images.githubusercontent.com/72448713/176744040-3e7a8de0-9fb8-431b-9cbd-ba054213f7ef.jpeg)  
### Step 2:
![Screenshot 2022-06-30 185641](https://user-images.githubusercontent.com/72448713/176744315-b7e72afe-c8e6-464f-ba4d-2ae8e948638c.jpg)
### Step 3:  Create and attach a policy
![Screenshot 2022-07-01 000254](https://user-images.githubusercontent.com/72448713/176752384-2e5ab16d-b322-4e0d-8a6b-5997563e42f4.jpg)  
### Step 4: Download certificates   
![Web capture_30-6-2022_19716_ap-south-1 console aws amazon com](https://user-images.githubusercontent.com/72448713/176744467-a94a49d2-0f4e-4f95-86e9-b1a8d13b207c.jpeg)  

## Create a table in DynamoDB to store the incoming sensor data  
![Web capture_30-6-2022_18486_ap-south-1 console aws amazon com](https://user-images.githubusercontent.com/72448713/176749568-80477d04-4867-43d2-b12f-fa998cd8e109.jpeg)  

## Create a rule to route messages  
### Step 1:  
![Screenshot 2022-06-30 184914](https://user-images.githubusercontent.com/72448713/176748501-02271f77-96b9-466f-8259-1dee7cacb9f6.jpg)  
### Step 2:  
![Screenshot 2022-06-30 184731](https://user-images.githubusercontent.com/72448713/176749079-b3055209-d3be-4cc1-a760-58e9357dae74.jpg)  
### step 3:  
![Web capture_30-6-2022_18511_ap-south-1 console aws amazon com](https://user-images.githubusercontent.com/72448713/176749811-ce127429-9ee9-46b0-8c49-3e39aaeefcea.jpeg)  

## Data received from sensor can be seen in DynamoDB table(table selected while creating the rule)   
![Screenshot 2022-06-30 194914](https://user-images.githubusercontent.com/72448713/176750232-3d233a28-fd9d-40bd-b7a3-350f2d509c76.jpg)
