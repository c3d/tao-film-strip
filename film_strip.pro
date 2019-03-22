# ******************************************************************************
# film_strip.pro                                                   Tao3D project
# ******************************************************************************
#
# File description:
#
#
#
#
#
#
#
#
# ******************************************************************************
# This software is licensed under the GNU General Public License v3
# (C) 2013, Baptiste Soulisse <baptiste.soulisse@taodyne.com>
# (C) 2013, Catherine Burvelle <catherine@taodyne.com>
# (C) 2013-2014,2019, Christophe de Dinechin <christophe@dinechin.org>
# (C) 2013, Jérôme Forissier <jerome@taodyne.com>
# ******************************************************************************
# This file is part of Tao3D
#
# Tao3D is free software: you can r redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Tao3D is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Tao3D, in a file named COPYING.
# If not, see <https://www.gnu.org/licenses/>.
# ******************************************************************************

MODINSTDIR = film_strip

include(../modules.pri)

OTHER_FILES = film_strip.xl
OTHER_FILES += doc/film_strip.doxy.h doc/Doxyfile.in

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
DOXYADDFILES = doc/hello_strip.ddd \
               doc/old_movie.ddd \
               doc/old_movie_fr.ddd \
               doc/old_video.ddd \
               doc/countdown.ddd
include(../modules_doc.pri)
