myfun_lsm.c


  Three hooks: 

  - Mkdir inode_hook, just prints out every time mkdir sys call is called. It is not registered;
  - Mkdir path_hook, just prints out every time mkdir sys call is called. It is registered;
  - Rmdir path_hook, it gives permission to remove a directory only to root user, else returns a permission error.

  The array of struct myfun_hooks[] used to register hooks via the macro LSM_HOOK_INIT. Is is read only after init, that is it can not be written after boot. 

  The init function, the key of the registration. In this example, it just adds the registered hooks. 

  The macro DEFINE_LSM, required to register our module. 
 
 
Kconfig


  The file needed to register our module in the Linux Kernel. 
  
  
Makefile 


  The file needed to compile our module
