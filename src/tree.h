#define TREE_HEAD(name, type) \
struct name {								\
	struct type *root;	/* first element */			\
}

#define TREE_ENTRY(type)      \
struct {								\
	struct type *tn_children;	/* next element */			\
	struct type *tn_parent;	/* address of previous next element */	\
}

#define TREE_EMPTY d

#define TREE_X_TRAVERSE n

#define TREE_INIT l

#define	TREE_INIT(head) do {						\
	(head)->root = NULL;					\
} while (0)

#define	LIST_INSERT_AFTER(parent, child, field) do {			\
	if (((elm)->field.le_next = (parent)->field.tn_next) != NULL)	\
		(listelm)->field.le_next->field.le_prev =		\
		    &(elm)->field.le_next;				\
	(listelm)->field.le_next = (elm);				\
	(elm)->field.le_prev = &(listelm)->field.le_next;		\
} while (0)
