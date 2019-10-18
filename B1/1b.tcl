 #creates a new simulator
set ns [new Simulator]
set nf [open prog1.nam w]
$ns namtrace-all $nf
set nd [open 1b.tr w]
$ns trace-all $nd
proc finish { } {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam prog1.nam &
exec awk -f 1b.awk 1b.tr &
exit 0
}
#creating nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
#linking nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 12Kb 10ms DropTail
#setting queue size of the link
$ns queue-limit $n1 $n2 5
#creating a udp connection in network simulator
set udp0 [new Agent/TCP]
$ns attach-agent $n0 $udp0
#set up CBR over udp
set cbr0 [new Application/FTP]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $udp0 $sink
#scheduling events
$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run 
