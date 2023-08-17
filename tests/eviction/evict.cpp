#include <umap/umap.h>
#include <fcntl.h>
#include <cstdlib>

#include <iostream>

int main() {
    //system("cp -f /home/liss/Dokumente/swdf.nt /home/liss/Dokumente/swdf2.nt");
    int fd = open("/home/liss/Dokumente/swdf2.nt", O_RDWR);
    void *map = umap(nullptr, 8192, PROT_READ | PROT_WRITE, UMAP_PRIVATE, fd, 0);

    char *page_1 = reinterpret_cast<char *>(map);
    char *page_2 = page_1 + 4096;

    std::cout << *page_1 << *page_2 << std::endl;

    std::cin.get();
    uadvise(map, 4096, UADV_REMOVE);
    std::cin.get();

    std::cout << *page_1 << std::endl;

    uunmap(map, 8192);
}
