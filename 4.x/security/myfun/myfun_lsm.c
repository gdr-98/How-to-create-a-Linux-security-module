  GNU nano 5.2                                                                                                    myfun_lsm.c                                                                                                                 
#include <linux/module.h>
#include <linux/lsm_hooks.h>
#include <linux/errno.h>
#include <linux/cred.h>
#include <linux/uidgid.h>

static kuid_t root_uid = {0};

/*
 * Not used
*/

static int myfun_inode_mkdir(struct inode *dir, struct dentry *dentry, umode_t mask) {
        printk (KERN_INFO "<myfun> Hello World! Inode_mkdir hook.\n");
        return 0;
}

/*
 * Hook registered
*/ 

static int myfun_path_mkdir(const struct path *dir, struct dentry *dentry, umode_t mask) {
        printk (KERN_INFO "<myfun_mkdir> Hello world! Path_mkdir hook.\n");
        return 0;
}

/*
 * Rmdir hook registered
*/

static int myfun_path_rmdir(const struct path *dir, struct dentry *dentry) {
        const struct cred *cred = get_current_cred();

        if (uid_eq (cred->uid, root_uid))
                return 0;

        printk (KERN_INFO "<myfun_rmdir> You shall not remove! ID:%d.\n", cred->uid.val);
        return -EPERM;
}

/*
* Registering hook among available hooks
*/

static struct security_hook_list myfun_hooks[] __lsm_ro_after_init = {
        LSM_HOOK_INIT(path_mkdir, myfun_path_mkdir),
        LSM_HOOK_INIT(path_rmdir, myfun_path_rmdir),
};

/*
* Adding hook to LSM hook list
*/

static int  __init myfun_init (void) {
        security_add_hooks (myfun_hooks, ARRAY_SIZE(myfun_hooks), "myfun");
        return 0;
}
