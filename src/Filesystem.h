#ifndef MAPLEENGINE_FILESYSTEM_H
#define MAPLEENGINE_FILESYSTEM_H

#include <vector>
#include <string>

namespace Filesystem {
    /** Read the entries in the given path.
     *
     * Returns false if it fails, otherwise fills 'dirEntries' with the contents of the directory.
     */
    bool entries(const std::string& path, std::vector<std::string>* dirEntries);

    /** Read the contents of a file.
     *
     * Returns false if it fails, otherwise fills 'contents' with the contents of the file.
     */
    bool readFile(const std::string& path, std::string* contents);
};


#endif //MAPLEENGINE_FILESYSTEM_H
