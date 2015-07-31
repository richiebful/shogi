COMPILER = clang
CFLAGS = -Wall
INCLUDE = ./
TARGET = shogi
OBJDIR = ../obj
SOURCES = main.c init.c check.c legal.c move.c input.c display.c clock.c
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
DEPENDS = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS) $(CFLAGS)

$(OBJDIR)/%.o: %.c
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET) ${OBJECTS:.o=.gcda}
