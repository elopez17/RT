#include <rt.h>

pthread_mutex_t	lock;

void	multithread(t_rt *rt)
{
	pthread_t		thread[THREADS];
	t_rt			rts[THREADS];
	int				t;
	int				rc;

	t = -1;
	pthread_mutex_init(&lock, NULL);
	while (++t < THREADS)
	{
		ft_memcpy((void*)&(rts[t]), (void*)rt, sizeof(t_rt));
		rts[t].ystart = 200 * t;
		rts[t].ymax = 200 * (t + 1);
		rts[t].ymax == 800 ? ++rts[t].ymax : 0;
		if ((rc = pthread_create(&(thread[t]), NULL, scene, &(rts[t]))))
			exit(-1);
	}
	t = -1;
	while (++t < THREADS)
		if ((rc = pthread_join(thread[t], NULL)))
			exit(-1);
	pthread_mutex_destroy(&lock);
}
