/*
    Debber CLI (non-graphical) interface
    Simple package manager as frontend to dpkg
    (C) 2022 Tyler887 (tylermageeshields@gmail.com)
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

/***********************************************************************************************/

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <yaml.h>

#include <curl/curl.h>

// main code
int main(int argc, char* argv[] ) {
  if ( argv[1] == 0 ) {
    puts("Debber 0.1 Alpha");
    puts("usage: debber <command> {<subcommand>} [options]");
    puts("");
    puts("Commands:");
    puts("    install: install debian app (do not append .deb)");
    puts("    remove: remove debian app (do not append .deb)");
    puts("    purge: remove debian app and config files (do not append .deb)");
    puts("    show: show metadata of package");
    puts("    update: update debber (for packages use \"upgrade\" instead)");
    puts("    upgrade: upgrade debian app (for debber itself use \"update\" instead)");
    puts("    search: search installable packages");
    puts("");
    puts("{x} ERROR: \"command\" is required");
    return 1;
  }
  if ( argv[1] != "install" and argv[1] != "remove" and argv[1] != "purge" and argv[1] != "show" amd argv[1] != "update" and argv[1] != "upgrade" and argv[1] != "search" ) {
    printf("{x} ERROR: invalid CLI command: ");
    puts(argv[1]);
    return 127;
  }
  if ( argv[1] == "install" ) {
    if ( geteuid() != 0 ) {
      puts("{x} ERROR: must run as root");
      return 1;
    }
    if ( argv[2] == 0 ) {
      puts("{x} ERROR: no package to install given by user in CLI");
      return 1;
    }
    char *url = "http://raw.githubusercontent.com/Tyler887/debber/sources/",argv;
    char outfilename[FILENAME_MAX] = "page.html";
    curl = curl_easy_init();                                                                                                                                                                                                                                                           
    if (curl)
    {   
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
      puts("{x} ERROR: could not init curl or download manifest");
      return 2;
    }
}
