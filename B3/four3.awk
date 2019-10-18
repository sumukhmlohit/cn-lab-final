BEGIN{
cbrcount=0;
tcpcount=0;
}
{
event=$1;
if(event=="r" && $5=="cbr")
{
cbrcount++;
}

if(event=="r"&& $5=="tcp")
{
tcpcount++;
}
}
END{
printf("No of udp packets: %d",cbrcount);
printf("No of tcp packets : %d",tcpcount);

}
