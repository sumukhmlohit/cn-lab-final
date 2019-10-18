#While processing using awk column value will be stored in following variable
#$1 -> Event
#$2 -> Time
#$3 -> Node id
#$4 -> Layer
#$5 -> Flags
#$6 -> Sequence Number
#$7 -> Packet Type
#$8 -> Packet Size 
BEGIN{
dcount = 0;
rcount = 0;
}
{
event = $1;
if(event == "d")
{
dcount++;
}
if(event == "r")
{
rcount++;
}
}
END {
printf("The no.of packets dropped : %d\n ",dcount);
printf("The no.of packets recieved : %d\n ",rcount);
}

