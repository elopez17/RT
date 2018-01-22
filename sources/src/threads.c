/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:37 by oabdalha          #+#    #+#             */
/*   Updated: 2018/01/19 15:51:53 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

pthread_mutex_t	g_lock;

void	multithread(t_rt *rt)
{
	pthread_t		thread[THREADS];
	t_rt			rts[THREADS];
	int				t;
	int				rc;

	t = -1;
	pthread_mutex_init(&g_lock, NULL);
	while (++t < THREADS)
	{
		ft_memcpy((void*)&(rts[t]), (void*)rt, sizeof(t_rt));
		rts[t].ystart = (((float)t / (float)THREADS) * 800.0f);
		rts[t].ymax = ((((float)t + 1.0f) / (float)THREADS) * 800.0f);
		rts[t].ymax == 800 ? ++rts[t].ymax : 0;
		if ((rc = pthread_create(&(thread[t]), NULL, scene, &(rts[t]))))
			exit(-1);
	}
	t = -1;
	while (++t < THREADS)
		if ((rc = pthread_join(thread[t], NULL)))
			exit(-1);
	pthread_mutex_destroy(&g_lock);
}
