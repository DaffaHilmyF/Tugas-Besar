#include "relasi.h"
#include "child.h"
#include "parent.h"
#include "Interface.h"

List_child C;
List_parent P;
List_relasi R;

address_parent aP;
address_child aC;
address_relasi aR;




int main(){



    createListChild(C);
    createListParent(P);
    createListRelasi(R);

    /** ISI DATA LIST CHILD **/
    createChildElmt(aC, "1", "Susu Kental Manis", 10, 1000);
    insertLastChild(C, aC);
    createChildElmt(aC, "2", "Kopi Susu", 10, 2000);
    insertLastChild(C, aC);
    createChildElmt(aC, "3", "Nescafe", 1, 5000);
    insertLastChild(C, aC);

    /** ISI DATA LIST PARENT **/
    createParentElmt(aP, "3", "Daffa Hilmy Fadhlurrohman", 5000);
    insertFirstParent(P, aP);
    createParentElmt(aP, "2", "Rana Ramadhani", 150000);
    insertFirstParent(P, aP);
    createParentElmt(aP, "1", "Fathuddin Anshari", 10000);
    insertFirstParent(P, aP);
    system("CLS");



    showMenu(C, P, R);



return 0;
}
