all: ping traceroute

%: %.c icmp-utils.c
	gcc -g $^ -o $@
	sudo setcap cap_net_raw+ep $@


clean:
	rm ping
