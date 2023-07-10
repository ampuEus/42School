# Race condition

A race condition is a behavior that occurs when two threads access a shared variable at the same time.

![Graphical race condition](./../img/raceCondition.png)

It is called a race condition due to the similarity between two threads competing to reach the resource first.

The most common symptom of a race condition is unpredictable values of variables that are shared between multiple threads. This results from the unpredictability of the order in which the threads execute. Sometime one thread wins, and sometime the other thread wins. At other times, execution works correctly. Also, if each thread is executed separately, the variable value behaves correctly.

Example in C:
<table>
<thead>
  <tr>
    <th>Code with no threads</th>
    <th>Code with Race Conditon</th>
    <th>Code with NO Race Conditon</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td><pre lang="c">
#include &ltstdio.h&gt
#include &ltstdint.h&gt

#define BIG 1000000000UL
uint32_t count = 0;

void count_to_big(void) {
	for (uint32_t i=0; i < BIG; i++)
		count++;
}

int main() {
	count_to_big();
	count_to_big();
	printf("Result -> Count = %u\n", count);
}</pre></td>
    <td><pre lang="c">
#include &ltstdio.h&gt
#include &ltstdint.h&gt
#include &ltpthread.h&gt

#define BIG 1000000000UL
uint32_t count = 0;

void * count_to_big(void *arg) {
	for (uint32_t i=0; i < BIG; i++)
		count++;
	return (NULL);
}

int main() {
	pthread_t t;
	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Result -> Count = %u\n", count);
}</pre>
    </td>
    <td><pre lang="c">
#include &ltstdio.h&gt
#include &ltstdint.h&gt
#include &ltpthread.h&gt

#define BIG 1000000000UL
uint32_t count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * count_to_big(void *arg) {
	for (uint32_t i=0; i < BIG; i++) {
		pthread_mutex_lock(&lock); // Thread will wait here until it can get the lock
		count++;
		pthread_mutex_unlock(&lock); // Other thread releases lock here
	}
	return (NULL);
}

int main() {
	pthread_t t;
	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Result -> Count = %u\n", count);
}
</pre>
    </td>
  </tr>
  <tr>
    <td>Output:<br>
    <pre>Result -> Count = 2000000000</pre>
    </td>
    <td>Output:<br>
    <pre>Result -> Count = 1?????????</pre>
    *Due to race conditions, the final number varies</td>
    <td>Output:<br>
    <pre>Result -> Count = 2000000000</pre>
    *In this specific example, using multi-threading doesn't make much sense as program execution takes a long time due to context switching between threads. It's just a simple example to demonstrate race conditions</td>
  </tr>
</tbody>
</table>
