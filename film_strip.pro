
MODINSTDIR = film_strip

include(../modules.pri)

OTHER_FILES = film_strip.xl
OTHER_FILES += doc/film_strip.doxy.h doc/Doxyfile.in
OTHER_FILES += film_strip2.xl

CRYPT_XL_SOURCES = film_strip2.xl
include(../crypt_xl.pri)

# Icon: http://www.iconfinder.com/icondetails/3787/128/film_movie_video_icon
# Author:  Everaldo Coelho - http://www.everaldo.com/ 
# License: LGPL. In category "Free / For commercial use (no backlink).
INSTALLS    += thismod_icon
INSTALLS    -= thismod_bin

inst_others.files = 2-pop.wav
inst_others.path  = $${MODINSTPATH}
QMAKE_TARGETS += inst_others
INSTALLS += inst_others

QMAKE_SUBSTITUTES = doc/Doxyfile.in
QMAKE_DISTCLEAN = doc/Doxyfile
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
DOXYADDFILES = doc/hello_strip.ddd.txt \
               doc/old_movie.ddd.txt \
               doc/old_movie_fr.ddd.txt \
               doc/old_video.ddd.txt \
               doc/countdown.ddd.txt
include(../modules_doc.pri)
