include ../common.inc

PROJECT_TARGET := libcommon.a
PROJECT_SRCS := cmdlineparser.cpp common.cpp getconsolewidth.cpp getmillisecondcounter.cpp logger.cpp prettyprint.cpp refcountobject.cpp stringhelper.cpp
PROJECT_OBJS := $(subst .cpp,.o,$(PROJECT_SRCS))
INCLUDES := $(BOOST_INCLUDE)
PRECOMP_H_GCH := commonincludes.h.gch




all: $(PRECOMP_H_GCH) $(PROJECT_TARGET)

clean:
	rm -f $(PROJECT_OBJS) $(PROJECT_TARGET) $(PRECOMP_H_GCH)

$(PROJECT_TARGET): $(PROJECT_OBJS)
	rm -f $@
	$(AR) rv $@ $^ 


	
