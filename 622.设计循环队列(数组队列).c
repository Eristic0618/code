// ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
// ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
// ���ʵ��Ӧ��֧�����²�����
// MyCircularQueue(k): �����������ö��г���Ϊ k ��
// Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
// Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
// enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
// deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
// isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
// isFull(): ���ѭ�������Ƿ�������

typedef struct
{
    int front;
    int rear;
    int k;
    int *a;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->front = obj->rear = 0;
    obj->k = k;
    obj->a = (int *)malloc(sizeof(int) * (k + 1));
    return obj;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        obj->a[obj->rear] = value;
        obj->rear++;
        if (obj->rear == obj->k + 1)
            obj->rear = 0;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        obj->front++;
        if (obj->front == obj->k + 1)
            obj->front = 0;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    if (obj->rear == 0)
        return obj->a[obj->k];
    else
        return obj->a[obj->rear - 1];
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->a);
    free(obj);
}