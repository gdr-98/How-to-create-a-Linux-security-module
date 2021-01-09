[...]

#ifdef CONFIG_SECURITY_MYFUN extern void __init myfun_add_hooks(void);
#else static inline void __init myfun_add_hooks(void) { }
#endif
