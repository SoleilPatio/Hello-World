/*
 * [CLS]:
 * 1. �ݩ�sysfs���ܧ� (/sys/class/misc/), ���ӬOsysfs��wrapper
 * 2. sysfs��kernel object ���O���Fdevice driver�A�Ȳ���
 * 3. misc driver�ϥ�major number 10 , �j�a�@�γo��major number
 */

/*
 * [CLS]:�T��linux file system
 * procfs: proc on /proc  (kernel �洫�T��)
 *	struct proc_dir_entry *proc_mkdir()
 * 	struct proc_dir_entry *proc_create()
 *
 * debugfs: debugfs on /sys/kernel/debug (debug��)
 * 	struct dentry *debugfs_create_dir()
 * 	struct dentry *debugfs_create_file()
 *
 *		(*1):procfs & debugfs���ۦ��A�i�H��seq_*��{,����"struct file_operations"
 *		(*2):struct file_operations:
 *			owner, read, write, llseek,.....�@����...
 *
 *
 * sysfs:  sysfs on /sys  (device driver �洫�T��)
 *	struct kobject *kobject_create_and_add()
 *	int sysfs_create_file()
 *	int sysfs_create_link()
 *	int device_create_file()
 *
 *		(*1):�S��struct file_operations�A�ӬO�� "struct device_attribute"
 *		(*2): struct device_attribute:
 * 	 		show,store ==> �N�u���o���
 *
 */



static const struct file_operations mydev_file_ops = {
                .owner = THIS_MODULE
};

struct miscdevice mydev_miscdevice = {
                .minor = MISC_DYNAMIC_MINOR,
                .name = "mydev",
                .mode = 0664,
                .fops = &mydev_file_ops
};






static ssize_t ksym_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i;

	mutex_lock(&dev->mutex);
	i = snprintf(buf, PAGE_SIZE, "%s\n", "hello");
	mutex_unlock(&dev->mutex);
	return i;


}

static ssize_t ksym_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	mutex_lock(&dev->mutex);
	kstrtoint(buf, 10, &var);
	mutex_unlock(&dev->mutex);
	return count;
}

/*
 * [CLS]:
 * 1.�o��create �@�� device_attribute "��Ƶ��c"
 * 2.�@��device_attribute �N�O�@��node file���ԭz
 * 3.�����ϥ�device_create_file()�N�L���create�X�ӡA�ݭn�̪��b�@��device���W
*/
static DEVICE_ATTR(ksym, 0664, ksym_show, ksym_store);
/*
 * <<<<<
 * #define DEVICE_ATTR(_name, _mode, _show, _store) \
 *		struct device_attribute dev_attr_##_name = __ATTR(_name, _mode, _show, _store)
 * >>>>>
 */

/*
<<<<<
		==> in <linux/sysfs.h>:
		struct attribute {
			const char *name;
			umode_t mode;
			#ifdef CONFIG_DEBUG_LOCK_ALLOC
			bool ignore_lockdep:1;
			struct lock_class_key *key;
			struct lock_class_key skey;
			#endif
		};


		==> in <linux/device.h>:
		//interface for exporting device attributes
		struct device_attribute {
			struct attribute attr;
			ssize_t (*show)(struct device *dev, struct device_attribute *attr,
					char *buf);
			ssize_t (*store)(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count);
		};
>>>>>
*/




void main()
{

	/*
	 * [CLS]: step 1
	 *  1. �إߤ@�� �W�� "mydev" �� struct device
	 *  2. �b /sys/class/misc/ �إߤ@�� "mydev" ���ؿ�(groups)
	 *
	 */

	ret = misc_register(&mydev_miscdevice); /*[CLS]:�|��Jmydev_miscdevice.this_device ( struct device ���c)*/
	/*
	 <<<<<
		 dev = MKDEV(MISC_MAJOR, misc->minor); ==> �إ� (majoe,minor)

		 misc->this_device = device_create_with_groups(
					 misc_class, ==> �Τ@�إߪ� class.  misc_class = class_create(THIS_MODULE, "misc");
					 misc->parent, ==> parent struct device
					 dev, ==> (major, minor) pair
					 (void*) misc,  ==> data pass for callback?
					 misc->groups, ==> list of attribute grops to be created
					 "%s",  ==> string for the device name
					 misc->name
	 	 	 	 	 );
	 >>>>>
	 */



	/*
	 * [CLS]:step 2
	 * ����n�]�wdma ops?
	 */
	arch_setup_dma_ops(mydev_miscdevice.this_device, 0, 0, NULL, false);
	/*
	>>>>>
		dev->archdata.dma_ops = &swiotlb_dma_ops;
	<<<<<
	*/


	/*
	 * [CLS]:step 3
	 * Create device node
	 * dev_attr_ksym : �O���e DEVICE_ATTR(ksym, 0664, ksym_show, ksym_store) �إߪ�"struct device_attribute" instance
	 */

	device_create_file(mydev_miscdevice.this_device, &dev_attr_ksym);

}

