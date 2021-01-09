[...]

#ifdef CONFIG_SECURITY_FOOBARexternvoid __init foobar_add_hooks(void);
#elsestaticinlinevoid __init foobar_add_hooks(void){ }
#endif
