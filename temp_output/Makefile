R:=$(shell pwd)

MKDIR:=mkdir

PROJECT_NAME:=obdhlab-termina
PLATFORM:=rtems5-leon3-qemu
TERMINA_OSAL_DIR:=/opt/termina-osal

include $(TERMINA_OSAL_DIR)/platform/$(PLATFORM)/platform.mk

TARGET_DIR_NAME:=$R/bin
TARGET:=$(TARGET_DIR_NAME)/$(PROJECT_NAME)

INCLUDE_DIRS+=$R/include

SRCS+=$(wildcard $R/*.c)
SRCS+=$(wildcard $R/src/./*.c)
SRCS+=$(wildcard $R/src/handlers/*.c)
SRCS+=$(wildcard $R/src/resources/*.c)
SRCS+=$(wildcard $R/src/service_libraries/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service1/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service12/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service19/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service20/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service3/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service4/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service5/*.c)
SRCS+=$(wildcard $R/src/service_libraries/pus_services/pus_service9/*.c)
SRCS+=$(wildcard $R/src/tasks/*.c)
SRCS+=$(wildcard $R/src/tasks/hk_fdir_mng/*.c)
SRCS+=$(wildcard $R/src/tasks/icu_manager/*.c)

OBJS+=$(patsubst %.c, %.o, $(patsubst $(TERMINA_OSAL_DIR)/%, $(TARGET_DIR_NAME)/termina/%, $(wildcard $(OSAL_SRCS))))
OBJS+=$(patsubst %.c, %.o, $(patsubst $R/%, $(TARGET_DIR_NAME)/%, $(SRCS)))

CPPFLAGS+=$(patsubst %, -I %, $(INCLUDE_DIRS))

DEPS:=$(patsubst %.o, %.d, $(OBJS))

all: $(TARGET)


$(TARGET_DIR_NAME)/termina/%.o: $(TERMINA_OSAL_DIR)/%.c
	@echo Building $<
	@$(MKDIR) -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c -o $@ $<

$(TARGET_DIR_NAME)/%.o: $(R)/%.c
	@echo Building $<
	@$(MKDIR) -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c -o $@ $<

$(TARGET): $(OBJS)
	@echo Linking $@
	@$(MKDIR) -p $(@D)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

clean: 
	@echo Cleaning up
	@$(RM) $(OBJS) $(DEPS) $(TARGET)

dist-clean: clean
	@echo Mr. Proper is cleaning up
	@$(RM) -rf $(TARGET_DIR_NAME)

-include $(DEPS)
