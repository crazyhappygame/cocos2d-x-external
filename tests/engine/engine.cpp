#include "engine.h"
#include "Box2D/Box2D.h"
#include "chipmunk/chipmunk.h"
#include "recast/Detour/DetourNode.h"
#include "zlib.h"
#include "uv.h"
#include "src/webp/encode.h"
#include "png.h"
#include "tiffio.h"
#include "rapidjson/rapidjson.h"
#include "openssl/crypto.h"
#include "LinearMath/btScalar.h"
#include "lua.h"

#include "ft2build.h"
#include FT_FREETYPE_H

#include <iostream>
#include <sstream>
#include <iomanip>


namespace engine {
    std::string getInfoActual()
    {
        std::ostringstream o;
        o << "External libs info:\n";
        o << "Box2D version: " << b2_version.major << "." << b2_version.minor
        << "." << b2_version.revision << "\n";
        o << "chipmunk: " << cpVersionString << "\n";
        dtNodeQueue q(10);
        o << "Recast dtNodeQueue: " << q.empty() << "\n";
        o << "zlib version: " << zlibVersion() << "\n";
        o << "freetype version: " << getFT2Version() << "\n";
        o << "uv: " << uv_version_string() << "\n";
        o << "webp: " << std::setfill('0') << std::setw(6) << std::hex << WebPGetEncoderVersion() <<  std::dec << "\n";
        o << "png: " << png_libpng_ver << "\n";
        o << "tiff: " << TIFFGetVersion() << "\n";
        o << "rapidjson: " << RAPIDJSON_VERSION_STRING << "\n";
        o << "libressl: " << SSLeay_version(SSLEAY_VERSION) << "\n";
        o << "bullet: " << btGetVersion() << "\n";
        o << "lua: " << LUA_VERSION << "\n";
        return o.str();
    }

    std::string getInfoExpected()
    {
        std::ostringstream o;
        o << "External libs info:\n";
        o << "Box2D version: 2.3.2\n";
        o << "chipmunk: 7.0.1\n";
        o << "Recast dtNodeQueue: 1\n";
        o << "zlib version: 1.2.8\n";
        o << "freetype version: 2.5.5\n";
        o << "uv: 1.23.1-dev\n";
        o << "webp: 000500\n";
        o << "png: 1.6.34\n";
        o << "tiff: LIBTIFF, Version 4.0.9\nCopyright (c) 1988-1996 Sam Leffler\nCopyright (c) 1991-1996 Silicon Graphics, Inc.\n";
        o << "rapidjson: 1.0.2\n";
        o << "libressl: LibreSSL 2.8.1\n" ;
        o << "bullet: 282\n";
        o << "lua: Lua 5.1\n";
        return o.str();
    }

    std::string getFT2Version()
    {
        FT_Int major, minor, patch;
        FT_Library _FTLibrary;
        assert(FT_Init_FreeType(&_FTLibrary) == 0);
        FT_Library_Version(_FTLibrary, &major, &minor, &patch);
        assert(FT_Done_FreeType(_FTLibrary) == 0);

        std::ostringstream o;
        o << major << "." << minor << "." << patch;
        return o.str();
    }
} // namespace engine
