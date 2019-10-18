set ns [new Simulator]
set nf [open lab2.nam w]
$ns namtrace-all $nf
set tf [open lab2.tr w]
$ns trace-all $tf
proc finish { } {
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam lab2.nam &
exec awk -f four3.awk lab2.tr &
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 0.4Mb 10ms DropTail
$ns duplex-link $n2 $n3 10Mb 10ms DropTail
set tcp0 [new Agent/TCP] 
# letters A,T,C,P are capital 
$ns attach-agent $n0 $tcp0
set udp1 [new Agent/UDP]
 # letters A,U,D,P are capital
$ns attach-agent $n1 $udp1
set null0 [new Agent/Null] 
# letters A and N are capital
$ns attach-agent $n3 $null0
set sink0 [new Agent/TCPSink]
 # letters A,T,C,P,S are capital
 $ns attach-agent $n3 $sink0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$ns connect $tcp0 $sink0
$ns connect $udp1 $null0
$ns at 0.1 "$cbr1 start"
$ns at 0.2 "$ftp0 start"
$ns at 0.5 "finish"
$ns run
