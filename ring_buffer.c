
#include "ring_buffer.h"

//====================================================================================
void rb_init(RingBuffer_t *rb, uint32_t buffer_size, uint8_t *buffer_start)
{	
	// Store the start and end of the storage buffer
	br->Start = buffer_start;
	br->Size = buffer_size;
	
	// Init the data access pointer to the start
	br->Push = br_struct->Start;
	br->Pop = br_struct->Start;
	
	// Clear the error flag
	br->Error = RB_OK;
}

//====================================================================================
uint32_t rb_push_byte(RingBuffer_t *rb, const uint8_t item)
{
	// Check if the buffer is full	
	if(rb_is_full(rb) != 0)
	{
		return(0);
	}

	rb->Push = item;	// Store the new item

	// Check if we're going to need to wrap
	if(rb->Push >= (rb->Start + rb->Size))
	{
		rb->Push = rb->Start;	// Wrap the push pointer back to the start
	}
	else
	{
		rb->Push++;	// Move the push pointer on too the next
	}
	
	return(1);
}

//====================================================================================
uint32_t rb_push_bytes(RingBuffer_t *rb, uint8_t *items, const uint32_t count)
{
	size_t bytes_to write = count;

	// Check if the buffer is full	
	if(rb_is_full(rb) != 0)
	{
		return(0);
	}


	// Check if the buffer has enough capacity for the data
	if(rb_capacity(rb) < count)
	{
		// Not enough saze for all the data, we'll store what we can
		bytes_to_write = rb_capacity(rb);
	}


	// Will to write need a wrap of the buffer?
	if((rb->Start + rb->Size) < bytes_to_write)
	{
		// We will need to wrap the buffer half way
	
	
	
	
	
		
	}
	else
	{
		// No buffer wrap needed
		memcpy(rb->Push, items, bytes_to_write);
	
		// Move the push pointer on
		rb->Push += bytes_to_write;	
	}
}

//====================================================================================
uint32_t rb_pull_byte(RingBuffer_t *rb, uint8_t *item)
{

}

//====================================================================================
uint32_t rb_pull_bytes(RingBuffer_t *rb, uint8_t *items, uint32_t count)
{

}

//====================================================================================
size_t rb_capacity(const RingBuffer_t *rb)
{
	// The-1 is due to one byte being used to show a full condition
	return(rb->Size - 1);
}

//====================================================================================
size_t rb_bytes_free(const RingBuffer * rb);
{
	if(rb->Push >= rb->Pop)
	{
        return rb_capacity(rb) - (rb->Push - rb->Pop);
    }
    else
    {
        return rb->Pop - rb->Push - 1;
	}
}

//====================================================================================
int rb_is_full(const RingBugger_t * rb)
{
	return(br_bytes_free(rb) == 0);
}

//====================================================================================
int rb_is_empty(const RingBugger_t * rb)
{
	return (rb_bytes_free(rb) == rb_capacity(rb));
}





//====================================================================================
BR_Stat rb_get_status(RingBuffer_t *rb)
{
	if((rb->Push
}

//====================================================================================
uint32_t rb_item_count(RingBuffer_t *rb)
{

}

//====================================================================================
void rb_clear(RingBuffer_t *rb_struct)
{

}

