#include <rt.h>

void	multithread(t_rt *rt)
{
	pthread_t		thread[THREADS];
	t_rt			rts[THREADS];
	pthread_attr_t	attr;
	int				t;
	int				rc;

	t = -1;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	while (++t < THREADS)
	{
		ft_memcpy((void*)&rts[t], (void*)rt, sizeof(t_rt));
		rts[t].ystart = 200 * t;
		rts[t].ymax = 200 * (t + 1);
		if ((rc = pthread_create(&thread[t], &attr, scene, (void *)&rts[t])))
			exit(-1);
	}
	pthread_attr_destroy(&attr);
	while (--t >= 0)
		if ((rc = pthread_join(thread[t], NULL)))
			exit(-1);
}
