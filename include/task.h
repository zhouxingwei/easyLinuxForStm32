#ifndef   OS_TASK_H
#define   OS_TASK_H

#ifdef __cplusplus
extern "C" {
#endif
#define NR_TASKS 8
#define NR_OPEN  2
#define SIGNAL_OPEN 3
#define HZ 100
//task status
#define TASK_RUNNING		0
#define TASK_INTERRUPTIBLE	1
#define TASK_UNINTERRUPTIBLE	2
#define TASK_ZOMBIE		3
#define TASK_STOPPED		4
#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef int (*fn_ptr)();
//36bytes
struct task_struct {
/* these are hardcoded - don't touch */
	unsigned long* pstack;
	char state;	/* -1 unrunnable, 0 runnable, >0 stopped */
	char exit_code;
	char priority;
	char signal;
	fn_ptr sig_fn[SIGNAL_OPEN];
	long counter;
	char pid;
	char father;
	char uid;
	char gid;
	long alarm;
	long utime;
	/* this is for file,in future will be support */
	/*unsigned short umask;
	struct m_inode * pwd;
	struct m_inode * root;
	char close_on_exec;
	struct file * filp[NR_OPEN];*/
};   

extern struct task_struct *task[NR_TASKS];
extern struct task_struct *current;
extern long volatile jiffies;
extern void sleep_on(struct task_struct ** p);
extern void interruptible_sleep_on(struct task_struct ** p);
extern void wake_up(struct task_struct ** p);

#ifdef __cplusplus
}
#endif

#endif
