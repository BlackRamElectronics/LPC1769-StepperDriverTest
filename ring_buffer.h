#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

typedef enum RB_Stat
{
	RB_OK	= 0,
	RB_FULL,
	RB_OVERFLOW,
	RB_UNDERFLOW
}BR_Stat;


typedef struct RingBuffer_t
{
	size_t ItemSize;
	uint8_t *Start;
	size_t *Size;
	void *Push;
	void *Pop;
	RB_Stat Error;
}RingBuffer_t;



void rb_init(RingBuffer_t *rb, uint32_t buffer_size, uint8_t *buffer_start);

uint32_t rb_push_byte(RingBuffer_t *rb, const uint8_t item);
uint32_t rb_push_bytes(RingBuffer_t *rb, const uint8_t *items, uint32_t count);

uint32_t rb_pull_byte(RingBuffer_t *rb, uint8_t *item);
uint32_t rb_pull_bytes(RingBuffer_t *rb, uint8_t *items, uint32_t count);

size_t rb_bytes_free(const RingBuffer * rb);
int rb_is_full(const RingBugger_t * rb);
int rb_is_empty(const RingBugger_t * rb);


BR_Stat rb_get_status(RingBuffer_t *rb);
uint32_t rb_item_count(RingBuffer_t *rb);
void rb_clear(RingBuffer_t *rb);

#endif // __RING_BUFFER_H__
