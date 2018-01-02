include ./Sources.mk
include ./Includes.mk
include ./makefile.conf

NAME=LPC1769-StepperTest
STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

LDSCRIPTS=-L. -L$(BASE)/ldscripts -T gcc.ld
LFLAGS=$(USE_NANO) $(USE_NOHOST) $(LDSCRIPTS) $(GC) $(MAP)

all: $(NAME)-$(CORE).axf $(NAME)-$(CORE).bin checksum

$(NAME)-$(CORE).axf: $(SOURCES) $(STARTUP)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@
	$(SIZE) $@
	
$(NAME)-$(CORE).bin:$(NAME)-$(CORE).axf
	$(OBJCOPY) -O binary $(NAME)-$(CORE).axf $(NAME)-$(CORE).bin

checksum:$(NAME)-$(CORE).bin
	../LPC-Checksum-Inserter/LPC-Checksum-Inserter $(NAME)-$(CORE).bin

#copy:checksum
#	cp $(NAME)-$(CORE).bin /media/reuben/DAPLINK/

clean: 
	rm -f $(NAME)*.axf *.map $(NAME)*.bin
