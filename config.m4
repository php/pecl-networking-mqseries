dnl $Id$
dnl config.m4 for extension mqseries

PHP_ARG_WITH(mqseries, for mqseries support,
[  --with-mqseries             Include mqseries support])

if test "$PHP_MQSERIES" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-mqseries -> check with-path
  SEARCH_PATH="/usr/local /usr /opt /opt/mqm"     # you might want to change this
  SEARCH_FOR="/inc/cmqcfc.h"  # you most likely want to change this
  if test -r $PHP_MQSERIES/; then # path given as parameter
     MQSERIES_DIR=$PHP_MQSERIES
  else # search default path list
     AC_MSG_CHECKING([for mqseries files in default path])
     for i in $SEARCH_PATH ; do
       if test -r $i/$SEARCH_FOR; then
         MQSERIES_DIR=$i
         AC_MSG_RESULT(found in $i)
       fi
     done
  fi

  if test -z "$MQSERIES_DIR"; then
     AC_MSG_RESULT([not found])
     AC_MSG_ERROR([Please reinstall the mqseries distribution])
  fi

  dnl # --with-mqseries -> add include path
  PHP_ADD_INCLUDE($MQSERIES_DIR/inc)

  dnl # --with-mqseries -> chech for lib and symbol presence
  LIBNAME=mqic # you may want to change this
  LIBSYMBOL=MQCONN # you most likely want to change this

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
     PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MQSERIES_DIR/lib, MQSERIES_SHARED_LIBADD)
     AC_DEFINE(HAVE_MQSERIESLIB,1,[ ])
  ],[
     AC_MSG_ERROR([wrong mqseries lib version or lib not found])
  ],[
     -L$MQSERIES_DIR/lib
  ])
  PHP_SUBST(MQSERIES_SHARED_LIBADD)

  PHP_NEW_EXTENSION(mqseries, mqseries.c, $ext_shared)
fi
