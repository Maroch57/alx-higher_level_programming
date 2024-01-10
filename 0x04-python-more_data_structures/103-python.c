#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

void print_python_bytes(PyObject *p)
{
	long int size;
	int k;
	char *t_strng = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &t_strng, &size);

	printf("  size: %li\n", size);
	printf("  trying string: %s\n", t_strng);
	if (size < 10)
		printf("  first %li bytes:", size + 1);
	else
		printf("  first 10 bytes:");
	for (k = 0; k <= size && k < 10; k++)
		printf(" %02hhx", t_strng[k]);
	printf("\n");
}

void print_python_list(PyObject *p)
{
        long int size = PyList_Size(p);
        int d;
        PyListObject *list = (PyListObject *)p;
        const char *ttype;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %li\n", size);
        printf("[*] Allocated = %li\n", list->allocated);
        for (d = 0; d < size; d++)
        {
                ttype = (list->ob_item[i])->ob_type->tp_name;
		printf("Element %i: %s\n", d, ttype);
                if (!strcmp(ttype, "bytes"))
                        print_python_bytes(list->ob_item[d]);
        }
}
