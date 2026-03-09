all: counter counter_sync tickets_sync

counter: counter.c
	gcc -o counter counter.c -Wall -pthread

counter_sync: counter_sync.c
	gcc -o counter_sync counter_sync.c -Wall -pthread

tickets_sync: tickets_sync.c
	gcc -o tickets_sync tickets_sync.c -Wall -pthread

clean:
	rm -f counter counter_sync tickets_sync