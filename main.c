#ifndef MAIN_C_INCLUDED
#define MAIN_C_INCLUDED


#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <myconio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "fonction.h"
#include <commctrl.h>
#include <wingdi.h>
#include <richedit.h>
//#include <commctrl.h></commctrl.h>
#define _WIN32_IE 0x305
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")
#define ID_STATIC2 1002
#define ID_EDIT 1003
#define ID_RECH_GROUP 1004
#define ID_RECH_GROUP_ADMIS 1005
#define ID_RECH_GROUP_REFUSE 1006
#define ID_RECH_GROUP_PASSABLE 1007
#define ID_RECH_GROUP_ASSEZBIEN 1008
#define ID_RECH_GROUP_BIEN 1009
#define ID_RECH_GROUP_TRESBIEN 1010
#define ID_TAUX_MOY 1011
#define ID_RECH_ETUDIANT 1012
#define ID_GENERER 1013
#define ID_SUPP_NOTE 1014
#define ID_ANNULEZ 1015
#define ID_SUPP_ETUDIANT 1016
#define ID_SUPP_GROUP 1017
#define ID_SUPP_MATIERE 1018
#define ID_ADD_MATIERE 1019
#define ID_ADD_NOTE 1020

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;
void Stealth();
void Stealth1();
int quit;
HWND stealth,hwnd;
HWND hname ,hprenom,hdate,hresultat,hmoy,hage,hout,hogo,Add,Finnish;
 HDC hdc,hdc1;
 HFONT hFont;
 HINSTANCE hThisInstance;
HWND hCtrl0_6,hCtrl0_7,hCtrl0_8;
HMENU hmenu ;
HWND hListView1,hListView2,edit2,edit3,cadre;
HWND hwndStatic,hwndStatic2,hwndStatic4,hwndStatic5,hwndStatic6,hwndStatic7,edit,edit4,hwndStatic3;
groupe *tab_g;
coefficient *tc;
int enrg=0;
int ng=0,nbm=0;
HBITMAP hlogoImage , hgenerateImage;
int intro=0 ;
char ch[100] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    InitCommonControls();
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, "Project C.bmp");
    wincl.hIconSm = LoadIcon (hThisInstance, "Project C.bmp");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("my project"),       /* Title Text */
           WS_OVERLAPPEDWINDOW|WS_EX_ACCEPTFILES|WS_MAXIMIZE, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1920,                 /* The programs width */
           1280,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    tab_g =recuperation_etud(&ng,"groupe.txt");
    tc=recuperation(&nbm,"coeficient.txt");
    ShowWindow (hwnd, nCmdShow);
    //Stealth();



    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;
    static HBITMAP  hBmp1;
    char code[50],code1[50],co[50],ds[50],ex[50];
    float coef,dsi,exi;
    char * ch[400];
    etudiant *g;
    HANDLE hIcon;
    //Stealth();
    /*if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/


    //tc=recuperation(&nbm,"coeficient.txt");


    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:

        switch(wParam)
        {
        case ID_RECH_GROUP:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_afficher_group(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_ADMIS:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_afficher_group_admis(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_REFUSE:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_afficher_group_refuse(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_PASSABLE:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_passable_groupe(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_ASSEZBIEN:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_assezbien_groupe(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_BIEN:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_bien_groupe(tab_g,ng,code);

                break;
        case ID_RECH_GROUP_TRESBIEN:

                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_tresbien_groupe(tab_g,ng,code);
                break;
        case ID_TAUX_MOY:
                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                fill_taux_moy_groupe(code);
                break;
        case ID_RECH_ETUDIANT:
                GetWindowText(edit,code,30);
                if(existe44(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                etudiant * q=recherche_etudiant(tab_g,ng,code);
                initlist2(hwnd,"Afficher un etudiant donné");
                fill_etudiant(q);
                fill_etudiant2(q);
                //printf("%s",q->code);
                //fill_taux_moy_groupe(code);
                break;
        case ID_GENERER:
                GetWindowText(edit,code,30);
                if(existe44(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code invalid","Error",MB_ICONERROR);
                    break;
                }
                etudiant * h=recherche_etudiant(tab_g,ng,code);
                //initlist2(hwnd,"Afficher un etudiant donné");
                bulltein(h,tc,nbm);
                //printf("%s",q->code);
                //fill_taux_moy_groupe(code);
                break;
        case ID_ANNULEZ:
                hideall();
                break;
        case ID_SUPP_NOTE:
                GetWindowText(edit,code,30);
                if(existe44(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code etudiant invalid","Error",MB_ICONERROR);
                    break;
                }
                h=recherche_etudiant(tab_g,ng,code);
                GetWindowText(edit2,code1,30);
                if(existe5(tab_g,ng,code,code1)==0){
                    MessageBox(hwnd,"Code matiere invalid","Error",MB_ICONERROR);
                    break;
                }
                int a=MessageBox(hwnd,"Voulez vous supprimer cette matière","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tab_g=supprimer_note2(tab_g,ng,tc,nbm,code,code1);
                    MessageBox(hwnd,"Matière Supprimer avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
                break;
        case ID_SUPP_ETUDIANT:
                GetWindowText(edit,code,30);
                if(existe44(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code etudiant invalid","Error",MB_ICONERROR);
                    break;
                }
                a=MessageBox(hwnd,"Voulez vous supprimer ce étudiant","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tab_g=supprimer_etudiant2(tab_g,ng,code);
                    MessageBox(hwnd,"Etudiant Supprimé avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
                break;
        case ID_SUPP_GROUP:
                GetWindowText(edit,code,30);
                if(existe33(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code groupe invalid","Error",MB_ICONERROR);
                    break;
                }
                a=MessageBox(hwnd,"Voulez vous supprimer ce groupe","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tab_g=supprimer_groupe2(tab_g,&ng,code);
                    MessageBox(hwnd,"Groupe Supprimé avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
                break;
        case ID_SUPP_MATIERE:
                GetWindowText(edit,code,30);
                if(existe1(tc,code,nbm)==0){
                    MessageBox(hwnd,"Code Matière invalid","Error",MB_ICONERROR);
                    break;
                }
                a=MessageBox(hwnd,"Voulez vous supprimer cette matière","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tc=supprimer_matiere(tc,&nbm,code);
                    tab_g=supp_all_notes(tab_g,ng,tc,nbm,code);
                    MessageBox(hwnd,"Matère Supprimée avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
                break;
        case ID_ADD_MATIERE:
                GetWindowText(edit,code,30);
                if((!(verif1(code) && existe1(tc,code,nbm)==NULL))){
                    MessageBox(hwnd,"Code Matière existant ou invalid","Error",MB_ICONERROR);
                    break;
                }
                GetWindowText(edit2,code1,30);
                if(!(verif1(code1))){
                    MessageBox(hwnd,"Nom invalid","Error",MB_ICONERROR);
                    break;
                }
                GetWindowText(edit3,co,30);
                if(test_float(co)==0){
                     MessageBox(hwnd,"Coefficient invalid","Error",MB_ICONERROR);
                    break;
                }
                coef=atof(co);
                if(coef<=0){
                     MessageBox(hwnd,"Coefficient invalid","Error",MB_ICONERROR);
                    break;
                }
                a=MessageBox(hwnd,"Voulez vous ajouter cette matière","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tc=ajoutmatiere2(tc,&nbm,saisie_matiere2(code,code1,coef));
                    MessageBox(hwnd,"Matère ajouter avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
                break;
        case ID_ADD_NOTE:
             GetWindowText(edit,code,30);
             if(existe44(tab_g,ng,code)==0){
                    MessageBox(hwnd,"Code etudiant invalid","Error",MB_ICONERROR);
                    break;
                }
             h=recherche_etudiant(tab_g,ng,code);
             matiere r;
             coefficient *pc;
             GetWindowText(edit2,code1,30);
             if((!(verif1(code) && existe1(tc,code1,nbm)!=NULL))){
                    MessageBox(hwnd,"Code Matière inexistant ou invalid","Error",MB_ICONERROR);
                    break;
                }
             if(!(existe5(tab_g,ng,code,code1)==0)){
                 MessageBox(hwnd,"L'etudiant a deja cette matière","Error",MB_ICONERROR);
                    break;
             }
             GetWindowText(edit3,ds,30);
                if(test_float(ds)==0){
                     MessageBox(hwnd,"Note ds invalid","Error",MB_ICONERROR);
                    break;
                }
            dsi=atof(ds);
                if(dsi<0||dsi>20){
                     MessageBox(hwnd,"Note ds invalid","Error",MB_ICONERROR);
                    break;
                }
            GetWindowText(edit4,ex,30);
                if(test_float(ex)==0){
                     MessageBox(hwnd,"Note ds invalid","Error",MB_ICONERROR);
                    break;
                }
            exi=atof(ex);
                if(exi<0||exi>20){
                     MessageBox(hwnd,"Note ds invalid","Error",MB_ICONERROR);
                    break;
                }
            pc=existe1(tc,code1,nbm);
            r.ds=dsi;
            r.ex=exi;
            strcpy(r.nomm,pc->nommat);
            strcpy(r.num_mat,code1);
            a=MessageBox(hwnd,"Voulez vous ajouter cette matière ","Attention",MB_ICONQUESTION|MB_YESNOCANCEL);
                if(a==2){
                    hideall();
                }
                if(a==6){
                    tab_g=ajouternote2(tab_g,ng,tc,nbm,code,r);
                    MessageBox(hwnd,"Matère ajouter avec succes","Success",MB_ICONASTERISK);
                    hideall();

                }
             break;






        case 0:
                printf("SAISIE NOMBRE MATIERES\n");
                saisie_taille(&nbm);
                tc=(coefficient*)malloc(nbm*sizeof(coefficient));
                remplir_coef(tc,nbm);
                printf("CONTENU DE TC\n");
                affiche_matiere(tc,nbm);
                enregistrement(tc,nbm,"coeficient.txt");
                printf("SAISIE NOMBRE GROUPES\n");
                saisie_taille(&ng);
                tab_g=(groupe*)malloc(ng*sizeof(groupe));
                remplir(tab_g,ng,tc,nbm);
                affiche_tab(tab_g,ng);
                enregistrement_etud(tab_g,ng,"groupe.txt");
                break;

        case 1:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_add_mat(hwnd,"Ajouter une Matière","Donner le code de Matière:",ID_ADD_MATIERE);
                break;
        case 2:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                tab_g=ajoutergroupe(tab_g,&ng,tc,nbm);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 3:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                tab_g=ajouteretudiant(tab_g,ng,tc,nbm);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 4:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_add_note(hwnd,"Ajouter une Note/Etudiant","Donner le code de L'Etudiant:",ID_ADD_NOTE);
                break;
        case 5:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_supp(hwnd,"Supprimer Matière","Donner le code de Matière:",ID_SUPP_MATIERE);
                break;
        case 6:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_supp(hwnd,"Supprimer Groupe","Donner le code de groupe:",ID_SUPP_GROUP);
                break;
        case 7:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_supp(hwnd,"Supprimer Etudiant","Donner le code de l'étudiant:",ID_SUPP_ETUDIANT);
                break;
        case 8:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_supp_note(hwnd,"Supprimer Matiere/Etudiant","Donner le code de l'étudiant:","Donner le code de la matière:",ID_SUPP_NOTE);
                break;
        case 9:
                hideall();

                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher tous les groupes");
                fill_afficher_tous(tab_g,ng);
                break;
        case 10:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher un groupe donné");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP);
                break;
        case 11:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_input2(hwnd,"Donner le code de l'étudiant","Afficher un etudiant donné",ID_RECH_ETUDIANT);
                break;
        case 50:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_input2(hwnd,"Donner le code de l'étudiant","Génerer Bulletin de Note",ID_GENERER);
                break;
        case 12:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher les etudiants ADMIS");
                fill_admis(tab_g,ng);
                break;
        case 13:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher les étudiants REFUSÉ");
                fill_refuse(tab_g,ng);
                break;
        case 14:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist3(hwnd,"Afficher les Matières");
                fill_afficher_matiere(tc,nbm);
                break;
         case 15:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher les étudiant Admis d'un groupe");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_ADMIS);
                break;
         case 16:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher les étudiant Refusés d'un groupe");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_REFUSE);
                break;
        case 17:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention:Passable");
                fill_passable(tab_g,ng);
                break;
        case 18:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention:Assez Bien");
                fill_assezbien(tab_g,ng);
                break;
        case 19:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention:Bien");
                fill_bien(tab_g,ng);
                break;
        case 20:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention:Trés Bien");
                fill_tresbien(tab_g,ng);
                break;
         case 21:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention d'un groupe:Passable");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_PASSABLE);
                break;
         case 22:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention d'un groupe:Assez Bien");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_ASSEZBIEN);
                break;
         case 23:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention d'un groupe:Bien");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_BIEN);
                break;
         case 24:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                initlist(hwnd,"Afficher par mention d'un groupe:Trés Bien");
                init_input(hwnd,"Donner le code de groupe",ID_RECH_GROUP_TRESBIEN);
                break;
         case 25:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                fill_taux_moy();

                break;
         case 26:
                hideall();
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;
                }
                init_taux_moy_groupe(hwnd,ID_TAUX_MOY);

                break;


        case 27:
                if(ng==0){
                    MessageBox(hwnd,"Allez a la Creation","Fichier vide",MB_ICONERROR);
                    break;
                }
                tab_g =recuperation_etud(&ng,"groupe.txt");
                tc=recuperation(&nbm,"coeficient.txt");
                intro++;
                MessageBox(hwnd,"Fichier Recuperer avec succes","SUCCES",MB_ICONINFORMATION);
                break;
        case 28:
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;

                }
                enregistrement(tc,nbm,"coeficient.txt");
                enregistrement_etud(tab_g,ng,"groupe.txt");
                enrg++;
                MessageBox(hwnd,"Fichier Enregistrer avec succes","SUCCES",MB_ICONINFORMATION);

                break;
        case 29:
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;

                }
                system("start coeficient.txt");
                break;
        case 30:
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;

                }
                system("start groupe.txt");
                break;
        case 51:

                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;

                }
                system("start main.txt");
                break;
        case 52:
                if(intro==0){
                    MessageBox(hwnd,"Allez a la recuperation","Error",MB_ICONERROR);
                    break;

                }
                system("start fonction.txt");
                break;


        case 31:
                if(enrg==0){
                    MessageBox(hwnd,"Il faut enregister avant de quitter","Attention",MB_ICONWARNING);
                    break;
                }
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    Stealth1();
                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;




        }
    case WM_CREATE :
       hIcon = LoadImage(0, _T("Project C.ico"), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
        if (hIcon) {
            //Change both icons to the same icon handle.
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_BIG, hIcon);

                //This will ensure that the application icon gets changed too.
            SendMessage(GetWindow(hwnd, GW_OWNER), WM_SETICON, ICON_SMALL, hIcon);
            SendMessage(GetWindow(hwnd, GW_OWNER), WM_SETICON, ICON_BIG, hIcon);
}
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"pr1.bmp",IMAGE_BITMAP,1920,1280,LR_LOADFROMFILE);

            //hBmp1=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {
            /*switch(wParam){
            case 0:
                hBmp=LoadImage(NULL,"pr1.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);break;
            case 9:
                hBmp1=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);break;
            }*/

         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);
            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);
            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            if(enrg==0){
                    quit=MessageBox(hwnd,"Voulez vous Enregister","Attention",MB_ICONQUESTION|MB_YESNO);
                    if(quit==7){
                        PostQuitMessage (0);
                        break;
                    }
                    else{
                        enregistrement(tc,nbm,"coeficient.txt");
                        enregistrement_etud(tab_g,ng,"groupe.txt");
                        enrg++;
                        MessageBox(hwnd,"Fichier Enregistrer avec succes","SUCCES",MB_ICONINFORMATION);
                    }

            }

            Stealth1();
                    /* send a WM_QUIT to the message queue */

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{

    int ngg=0;
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU hex=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU hex2=CreateMenu();
    HMENU hex3=CreateMenu();
    HMENU hex4=CreateMenu();
    groupe *tab_gg =recuperation_etud(&ngg,"groupe.txt");
    /*coefficient *tcg=recuperation(&nbm,"coeficient.txt");*/

    if(ngg==0){
        AppendMenu(hmenu,MF_STRING,0,"CREATION");
    }
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp,"MISE À JOUR");

     AppendMenu(htp,MF_POPUP,(UINT_PTR)hex,"AJOUT");
        AppendMenu(hex,MF_STRING,1,"AJOUT MATIERE");
        AppendMenu(hex,MF_STRING,2,"AJOUT GROUP");
        AppendMenu(hex,MF_STRING,3,"AJOUT ETUDIANT");
        AppendMenu(hex,MF_STRING,4,"AJOUT Matiere/Etudiant");
    AppendMenu(htp,MF_POPUP,(UINT_PTR)hex1,"SUPPRIMER");
        AppendMenu(hex1,MF_STRING,5,"SUPPRIMER MATIERE");
        AppendMenu(hex1,MF_STRING,6,"SUPPRIMER GROUP");
        AppendMenu(hex1,MF_STRING,7,"SUPPRIMER ETUDIANT");
        AppendMenu(hex1,MF_STRING,8,"SUPPRIMER Matiere/Etudiant");




     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Recherche et Affichage");

      AppendMenu(htp1,MF_STRING,9,"Afficher tous les groupes");
      AppendMenu(htp1,MF_STRING,10,"Afficher un groupe donné");
      AppendMenu(htp1,MF_STRING,11,"Afficher un etudiant donné");
      AppendMenu(htp1,MF_STRING,50,"Génerer Bulletin de note");
      AppendMenu(htp1,MF_STRING,12,"Afficher les etudiant ADMIS");
      AppendMenu(htp1,MF_STRING,13,"Afficher les etudiant REFUSÉ");
      AppendMenu(htp1,MF_STRING,14,"Afficher les matiere");
      AppendMenu(htp1,MF_STRING,15,"Afficher ADMIS d'un groupe donné");
      AppendMenu(htp1,MF_STRING,16,"Afficher REFUSÉ d'un groupe donné");
      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex2,"Afficher par mention");
      AppendMenu(hex2,MF_STRING,17,"Passable");
      AppendMenu(hex2,MF_STRING,18,"Assez Bien");
      AppendMenu(hex2,MF_STRING,19,"Bien");
      AppendMenu(hex2,MF_STRING,20,"Trés Bien");
      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex3,"Afficher par mention d'un groupe donné");
      AppendMenu(hex3,MF_STRING,21,"Passable");
      AppendMenu(hex3,MF_STRING,22,"Assez Bien");
      AppendMenu(hex3,MF_STRING,23,"Bien");
      AppendMenu(hex3,MF_STRING,24,"Trés Bien");
      AppendMenu(htp1,MF_STRING,25,"Taux de Reussite|Moyenne generale");
      AppendMenu(htp1,MF_STRING,26,"Taux de Reussite|Moyenne generale d'un groupe donné");
      AppendMenu(hmenu,MF_STRING,27,"Recuperation");
      AppendMenu(hmenu,MF_STRING,28,"Enregistement");
      AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hex4,"Fichiers");
       AppendMenu(hex4,MF_STRING,29,"coeficient");
        AppendMenu(hex4,MF_STRING,30,"groupe");
        AppendMenu(hex4,MF_STRING,51,"main.c");
        AppendMenu(hex4,MF_STRING,52,"fonction.h");






    AppendMenu(hmenu,MF_STRING,31,"Quitter");
   SetMenu(hwnd,hmenu);
}
void lista1(HWND hWnd,HINSTANCE hInstance){

//    hideall();
    LVCOLUMN lvc = { 0 };
    LVITEM   lv  = { 0 };
    hListView1 = CreateWindowEx(0,WC_LISTVIEW,
                                 NULL,
                                    WS_CHILD|LVS_REPORT|WS_VISIBLE|WS_BORDER ,
                                    400,
                                 200,
                                 770,
                                 500,
                                 hWnd,
                                 (HMENU) 2,
                                 hInstance,
                                 NULL);
        hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Time New Roman");

        SendMessage (hListView1, WM_SETFONT,hFont , TRUE);

                                 //lvc.fmt  = LVCFMT_CENTER;
        ListView_SetTextBkColor(hListView1,RGB(192,192,192));
        ListView_Arrange(hListView1,LVA_DEFAULT);
        ListView_SortItemsEx(hListView1,0,0);
        ListView_SetExtendedListViewStyle(hListView1,LVS_EX_HEADERDRAGDROP|LVS_SORTDESCENDING|
                                          LVS_EX_FULLROWSELECT|LVS_EX_UNDERLINEHOT|
                                          LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
        ListView_SetBkColor(hListView1,RGB(192,192,192));
        ListView_SortItems(hListView1,2,3);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);
        lvc.mask = LVCF_TEXT | LVCF_WIDTH  | LVCF_FMT;
        lvc.fmt  = LVCFMT_CENTER;
        lvc.iSubItem = 0;
        lvc.cx       = 50;
        lvc.pszText  = TEXT("Groupe");
        ListView_InsertColumn(hListView1, 0, &lvc);


        lvc.iSubItem = 1;
        lvc.cx       = 50;
        lvc.pszText  = TEXT("ID");
        ListView_InsertColumn(hListView1, 1, &lvc);
        //lvc.fmt  = LVCFMT_LEFT;
        lvc.iSubItem = 2;
        lvc.cx       = 70;
        lvc.pszText  = TEXT("Nom");
        ListView_InsertColumn(hListView1, 2, &lvc);

        lvc.iSubItem = 3;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Prenom");
        ListView_InsertColumn(hListView1, 3, &lvc);
        lvc.iSubItem = 4;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Date de naissance");
        ListView_InsertColumn(hListView1, 4, &lvc);
        lvc.iSubItem = 5;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Moyenne");
        ListView_InsertColumn(hListView1, 5, &lvc);
        lvc.iSubItem = 6;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Resultat");
        ListView_InsertColumn(hListView1, 6, &lvc);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10){
                                sprintf(res,"ADMIS");
                            }
                            else
                                sprintf(res,"REFUSE");
                            lv.iItem = iItem;
                            ListView_InsertItem(hListView1, &lv);
                            ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                            ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                            ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                            ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                            ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                            ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                            ListView_SetItemText(hListView1, iItem, 6, TEXT(res));

                    }


            }

                /* Add some rows. */
       /* lv.iItem = 0;
        ListView_InsertItem(hListView1, &lv);
        ListView_SetItemText(hListView1, 0, 0, TEXT("3"));
        ListView_SetItemText(hListView1, 0, 1, TEXT("Friends"));
        ListView_SetItemText(hListView1, 0, 2, TEXT("500"));
        ListView_SetItemText(hListView1, 0, 3, TEXT("Alright"));
        ListView_SetCheckState(hListView1, 0, TRUE);
        lv.iItem = 1;
        ListView_InsertItem(hListView1, &lv);
        ListView_SetItemText(hListView1, 1, 0, TEXT("2"));
        ListView_SetItemText(hListView1, 1, 1, TEXT("Survivor"));
        ListView_SetItemText(hListView1, 1, 2, TEXT("970,000"));
        ListView_SetItemText(hListView1, 1, 3, TEXT("Please, not again"));
        ListView_SetCheckState(hListView1, 1, FALSE);
        lv.iItem = 2;
        ListView_InsertItem(hListView1, &lv);
        ListView_SetItemText(hListView1, 2, 0, TEXT("1"));
        ListView_SetItemText(hListView1, 2, 1, TEXT("shit"));
        ListView_SetItemText(hListView1, 2, 2, TEXT("shit"));
        ListView_SetItemText(hListView1, 2, 3, TEXT("shit"));
        ListView_SetBkColor(hListView1, RGB(255,61,205));
        ListView_Arrange(hListView1,0);
        //ListView_DeleteItem(hListView1,2);
        //ListView_DeleteAllItems(hListView1);
        //SendMessage(hListView1, LVM_GETCOLUMN, 0, 0);
        //MessageBox(hWnd,TEXT(LVM_GETCOLUMN), "QUITTER", MB_YESNO | MB_ICONQUESTION );
       // int count = (int)::SendMessage(hWndHdr, HDM_GETITEMCOUNT, 0, 0L);*/




}
void hideall(){
    DestroyWindow(hListView1);
    DestroyWindow(hListView2);
    DestroyWindow(hwndStatic);
    DestroyWindow(hwndStatic2);
    DestroyWindow(hCtrl0_6);
    DestroyWindow(hCtrl0_7);
    DestroyWindow(hCtrl0_8);
    DestroyWindow(hwndStatic3);
    DestroyWindow(hwndStatic4);
    DestroyWindow(edit);
    DestroyWindow(edit2);
    DestroyWindow(edit3);
    DestroyWindow(cadre);


}
void init_input(HWND hwnd,const char * c,int id){
    hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(c), WS_CHILD|WS_VISIBLE|WS_BORDER  ,
               540, 100, 195, 20, hwnd, NULL, NULL, NULL);
                hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);


        //SendMessage (hCtrl0_7, WM_SETFONT,hFont , TRUE);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES ,

                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 740, 100, 100, 20,
                                                 hwnd, (HMENU)ID_EDIT, NULL, 0);

    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Rechercher", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 850, 100, 80, 20, hwnd, id, hThisInstance, 0);


   // SendMessage(hwndStatic2,WM_SETTEXT,(LPARAM) c,TRUE);

}
void initlist(HWND hwnd,const char * c){
    //char * ch;
   // sprintf(ch,c);
   /* hwndStatic = CreateWindowW(WC_STATICW ,NULL, WS_CHILD|WS_VISIBLE  ,
               560, 60, 360, 35, hwnd, NULL, NULL, NULL);*/
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |BS_GROUPBOX|BS_CENTER|
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 265, 60, 1045, 700, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);
     hListView1 = CreateWindowEx(0,WC_LISTVIEW,
                                 NULL,
                                    WS_CHILD|LVS_REPORT|WS_VISIBLE|WS_BORDER ,
                                    305,
                                 150,
                                 965,
                                 600,
                                 hwnd,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
        ListView_SetExtendedListViewStyle(hListView1,LVS_EX_HEADERDRAGDROP|LVS_SORTDESCENDING|
                                          LVS_EX_FULLROWSELECT|LVS_EX_UNDERLINEHOT|
                                          LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
        hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

        SendMessage (hListView1, WM_SETFONT,hFont , TRUE);

        LVCOLUMN lvc = { 0 };
        lvc.mask = LVCF_TEXT | LVCF_WIDTH  | LVCF_FMT;
        lvc.fmt  = LVCFMT_CENTER;
        lvc.iSubItem = 0;
        lvc.cx       = 75;
        lvc.pszText  = TEXT("Groupe");
        ListView_InsertColumn(hListView1, 0, &lvc);


        lvc.iSubItem = 1;
        lvc.cx       = 100;

        lvc.pszText  = TEXT("       ID");
        lvc.fmt  = LVCFMT_LEFT;
        ListView_InsertColumn(hListView1, 1, &lvc);
        lvc.fmt  = LVCFMT_CENTER;
        lvc.iSubItem = 2;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Nom");
        ListView_InsertColumn(hListView1, 2, &lvc);

        lvc.iSubItem = 3;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Prenom");
        ListView_InsertColumn(hListView1, 3, &lvc);
        lvc.iSubItem = 4;
        lvc.cx       = 170;
        lvc.pszText  = TEXT("Date de naissance");
        ListView_InsertColumn(hListView1, 4, &lvc);
        lvc.iSubItem = 5;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Moyenne");
        ListView_InsertColumn(hListView1, 5, &lvc);
        lvc.iSubItem = 6;
        lvc.cx       = 170;
        lvc.pszText  = TEXT("Resultat");
        ListView_InsertColumn(hListView1, 6, &lvc);

}
void initlist3(HWND hwnd,const char * c){
    //char * ch;
   // sprintf(ch,c);
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |BS_GROUPBOX|BS_CENTER|
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 415, 60, 695, 400, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 30, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

        SendMessage (cadre, WM_SETFONT,hFont , TRUE);
     hListView1 = CreateWindowEx(0,WC_LISTVIEW,
                                 NULL,
                                    WS_CHILD|LVS_REPORT|WS_VISIBLE|WS_BORDER ,
                                    510,
                                 150,
                                 500,
                                 300,
                                 hwnd,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
        ListView_SetExtendedListViewStyle(hListView1,LVS_EX_HEADERDRAGDROP|LVS_SORTDESCENDING|
                                          LVS_EX_FULLROWSELECT|LVS_EX_UNDERLINEHOT|
                                          LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
        hFont=CreateFontA( 30, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

        SendMessage (hListView1, WM_SETFONT,hFont , TRUE);
        SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
        LVCOLUMN lvc = { 0 };
        lvc.mask = LVCF_TEXT | LVCF_WIDTH  | LVCF_FMT;
        lvc.fmt  = LVCFMT_CENTER;



        lvc.iSubItem = 0;
        lvc.cx       = 190;
        lvc.pszText  = TEXT("Nom");
        ListView_InsertColumn(hListView1, 1, &lvc);
        //lvc.fmt  = LVCFMT_LEFT;
        lvc.iSubItem = 1;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Code");
        ListView_InsertColumn(hListView1, 2, &lvc);

        lvc.iSubItem = 2;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Coefficent");
        ListView_InsertColumn(hListView1, 3, &lvc);


}
void fill_afficher_tous(groupe *tab_g,int ng){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10){
                                sprintf(res,"ADMIS");
                            }
                            else
                                sprintf(res,"REFUSÉ");
                            lv.iItem = iItem;
                            ListView_InsertItem(hListView1, &lv);
                            ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                            ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                            ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                            ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                            ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                            ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                            ListView_SetItemText(hListView1, iItem, 6, TEXT(res));

                    }


            }

}
void fill_afficher_matiere(coefficient * tc,int nbm){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        coefficient *pc;
            for (pc=tc;pc<tc+nbm;pc++){
                int iItem;
                iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                char code[50],nom[50],coef[50];
                sprintf(coef,"%.2f",pc->coef);
                sprintf(code,"%s",pc->codemat);
                sprintf(nom,"%s",pc->nommat);
                lv.iItem = iItem;
                ListView_InsertItem(hListView1, &lv);
                ListView_SetItemText(hListView1, iItem, 0, TEXT(nom));
                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                ListView_SetItemText(hListView1, iItem, 2, TEXT(coef));



            }

}
void fill_afficher_group(groupe * tab_g,int ng,char * c){
        ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0)
                    {int iItem;

                    for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10){
                                sprintf(res,"ADMIS");
                            }
                            else
                                sprintf(res,"REFUSÉ");
                            lv.iItem = iItem;
                            ListView_InsertItem(hListView1, &lv);
                            ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                            ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                            ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                            ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                            ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                            ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                            ListView_SetItemText(hListView1, iItem, 6, TEXT(res));

                    }
                    }


            }

}
void fill_admis(groupe * tab_g,int ng){
     ListView_DeleteAllItems(hListView1);


        LVITEM   lv  = { 0 };
        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10){
                                g++;
                                sprintf(res,"ADMIS");
                                lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }


                    }


            }
        if(g==0){
            MessageBox(hwnd,"Aucun étudiant est ADMIS","Rien Trouvé",MB_ICONINFORMATION);
        }



}
void fill_refuse(groupe * tab_g,int ng){
     ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy<10){
                                    g++;
                                sprintf(res,"REFUSÉ");
                                lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }


                    }


            }
     if(g==0){
            MessageBox(hwnd,"Aucun étudiant est REFUSE","Rien Trouvé",MB_ICONINFORMATION);
        }



}
void fill_afficher_group_admis(groupe * tab_g,int ng,char * c){
        ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0)
                    {int iItem;

                    for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10){
                                    g++;
                                sprintf(res,"ADMIS");
                                lv.iItem = iItem;
                            ListView_InsertItem(hListView1, &lv);
                            ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                            ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                            ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                            ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                            ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                            ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                            ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                    }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant est ADMIS","Rien Trouvé",MB_ICONINFORMATION);
        }


}
void fill_afficher_group_refuse(groupe * tab_g,int ng,char * c){
        ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0)
                    {int iItem;

                    for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy<10){
                                    g++;
                                sprintf(res,"REFUSÉ");
                                lv.iItem = iItem;
                            ListView_InsertItem(hListView1, &lv);
                            ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                            ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                            ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                            ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                            ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                            ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                            ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                    }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant est REFUSE","Rien Trouvé",MB_ICONINFORMATION);
        }


}
void fill_passable(groupe *tab_g,int ng){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=10&& q->moy<12){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention passable","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_passable_groupe(groupe *tab_g,int ng,char * c){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0){
                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if((q->moy>=10)&& (q->moy<12)){
                                g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                }


            }
               if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention passable","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_assezbien(groupe *tab_g,int ng){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=12&& q->moy<14){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }


            }
               if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Assez-Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_assezbien_groupe(groupe *tab_g,int ng,char * c){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0){
                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=12&& q->moy<14){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                }


            }
                  if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Assez-Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_bien(groupe *tab_g,int ng){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=14&& q->moy<16){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }


            }
                  if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_bien_groupe(groupe *tab_g,int ng,char * c){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0){
                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=14&& q->moy<16){
                                   g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_tresbien(groupe *tab_g,int ng){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {

                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=16){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Tres Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_tresbien_groupe(groupe *tab_g,int ng,char * c){
    ListView_DeleteAllItems(hListView1);


    LVITEM   lv  = { 0 };
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_LABELTIP,TRUE);
        //SendMessage(hListView1,LVM_SETEXTENDEDLISTVIEWSTYLE,P,TRUE);
//       ListView_SetExtendedListViewStyleEx(hListView1,0,LVSCW_AUTOSIZE);
        //ListView_Arrange(hListView1,LVA_SNAPTOGRID);

        groupe *p;
        etudiant *q;
        matiere *r;
        int ne;
        int g=0;
        for(p=tab_g;p<tab_g+ng;p++)
            {
                if(strcmp(c,p->codeg)==0){
                int iItem;

                for(q=p->te;q<p->te+p->nb_et;q++)
                    {

                            iItem=SendMessage(hListView1,LVM_GETITEMCOUNT,0,0);
                            char ng1[50],code[50],nom[50],prenom[50],date[50],moy[50],res[50];
                            sprintf(ng1,"%s",p->codeg);
                            sprintf(code,"%s",q->code);
                            sprintf(nom,"%s",q->nom);
                            sprintf(prenom,"%s",q->prenom);
                            sprintf(date,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
                            sprintf(moy,"%.2f",q->moy);
                            if(q->moy>=16){
                                    g++;
                                sprintf(res,"ADMIS");
                                 lv.iItem = iItem;
                                ListView_InsertItem(hListView1, &lv);
                                ListView_SetItemText(hListView1, iItem, 0, TEXT(ng1));
                                ListView_SetItemText(hListView1, iItem, 1, TEXT(code));
                                ListView_SetItemText(hListView1, iItem, 2, TEXT(nom));
                                ListView_SetItemText(hListView1, iItem, 3, TEXT(prenom));
                                ListView_SetItemText(hListView1, iItem, 4, TEXT(date));
                                ListView_SetItemText(hListView1, iItem, 5, TEXT(moy));
                                ListView_SetItemText(hListView1, iItem, 6, TEXT(res));
                            }



                    }
                }


            }
             if(g==0){
            MessageBox(hwnd,"Aucun étudiant avec une mention Tres Bien","Rien Trouvé",MB_ICONINFORMATION);
        }

}
void fill_taux_moy(HWND hwnd){
    float m=calcul_moy(tab_g,ng);
    float pp=calcul_taux(tab_g,ng);
    hwndStatic = CreateWindowW(WC_STATICW ,NULL, WS_CHILD|WS_VISIBLE  ,
               530, 60, 380, 35, hwnd, NULL, NULL, NULL);
    HWND hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, ("Afficher Taux de Reussite et Moyenne Generale"), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|WS_MAXIMIZE|0x00000001 , 66, 0, 66, 23, hwndStatic, NULL, NULL, 0);
    hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
    hFont=CreateFontA( 40, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

    sprintf(ch,"Le Taux de Reussite = %.2f%% \nLa moyenne generale = %.2f",pp,m);
                //printf("%.2f",pp);
                /*sprintf(ch,"Le Taux de Reussite est %.2f  et la moyenne generale =  %.2f",pp,m);*/
    hwndStatic2 = CreateWindowEx(0,WC_STATIC ,"", WS_CHILD|WS_VISIBLE  ,
               480, 110,480,150, hwnd, NULL, NULL, NULL);
               SendMessage (hwndStatic2, WM_SETFONT,hFont , TRUE);
    SetWindowTextA(hwndStatic2,ch);
}
void init_taux_moy_groupe(HWND hwnd,int id){
    hwndStatic = CreateWindowW(WC_STATICW ,NULL, WS_CHILD|WS_VISIBLE  ,
               480, 60, 510, 35, hwnd, NULL, NULL, NULL);
    HWND hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, ("Afficher Taux de Reussite et Moyenne Generale d'un groupe"), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|WS_MAXIMIZE|0x00000001 , 66, 0, 66, 23, hwndStatic, NULL, NULL, 0);
    hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
    hFont=CreateFontA( 40, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

//    sprintf(ch,"Le Taux de Reussite = %.2f%% \nLa moyenne generale = %.2f",pp,m);
                //printf("%.2f",pp);
                /*sprintf(ch,"Le Taux de Reussite est %.2f  et la moyenne generale =  %.2f",pp,m);*/
    hwndStatic2 = CreateWindowEx(0,WC_STATIC ,"", WS_CHILD|WS_VISIBLE  ,
               480, 110,500,150, hwnd, NULL, NULL, NULL);
               SendMessage (hwndStatic2, WM_SETFONT,hFont , TRUE);
    hwndStatic3 = CreateWindowEx(0,WC_STATIC ,("Donner le code de groupe:"), WS_CHILD|WS_VISIBLE  ,
               1020, 130, 200, 120, hwnd, NULL, NULL, NULL);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 50, 30, 100, 23,
                                                 hwndStatic3, (HMENU)ID_EDIT, NULL, 0);

    hCtrl0_7 = CreateWindowEx(0, WC_BUTTON, "Rechercher", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 1080, 190, 80, 23, hwnd, id, hThisInstance, 0);

}
void fill_taux_moy_groupe(char * c){
    float m=calcul_moy_group(tab_g,ng,c);
    float pp=calcul_taux_group(tab_g,ng,c);
    sprintf(ch,"Le Taux de Reussite = %.2f%% \nLa moyenne generale = %.2f",pp,m);
    SetWindowTextA(hwndStatic2,ch);
}
void init_input2(HWND hwnd,const char * c,const char *d,int id){
    cadre = CreateWindowEx(0, WC_BUTTON, (d), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|BS_GROUPBOX|BS_CENTER , 500, 60, 465,340, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);
    hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(c), WS_CHILD|WS_VISIBLE|WS_BORDER  ,
               540, 100, 195, 20, hwnd, NULL, NULL, NULL);
                hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES ,

                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 740, 100, 100, 20,
                                                 hwnd, (HMENU)ID_EDIT, NULL, 0);

    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Rechercher", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 850, 100, 80, 20, hwnd, id, hThisInstance, 0);
   // SendMessage(hwndStatic2,WM_SETTEXT,(LPARAM) c,TRUE);

}
void initlist2(HWND hwnd,const char * c){
    //char * ch;
   // sprintf(ch,c);
    DestroyWindow(hListView2);
    DestroyWindow(hwndStatic3);

     hListView2 = CreateWindowEx(0,WC_LISTVIEW,
                                 NULL,
                                    WS_CHILD|LVS_REPORT|WS_VISIBLE|WS_BORDER ,
                                    530,
                                 240,
                                 400,
                                 150,
                                 hwnd,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hwndStatic3=CreateWindowEx(0,WC_STATIC,
                                 ("Nom:"),
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    50,
                                 80,
                                 40,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hname = CreateWindowEx(0,WC_STATIC,
                                 NULL,
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    95,
                                 80,
                                 100,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hwndStatic4=CreateWindowEx(0,WC_STATIC,
                                 ("Prénom:"),
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    200,
                                 80,
                                 60,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hprenom = CreateWindowEx(0,WC_STATIC,
                                 NULL,
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    265,
                                 80,
                                 100,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hwndStatic5=CreateWindowEx(0,WC_STATIC,
                                 ("Date de Naissance:"),
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    50,
                                 105,
                                 140,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hdate = CreateWindowEx(0,WC_STATIC,
                                 NULL,
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    195,
                                 105,
                                 120,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hwndStatic6=CreateWindowEx(0,WC_STATIC,
                                 ("Moyenne:"),
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    50,
                                 130,
                                 80,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hmoy = CreateWindowEx(0,WC_STATIC,
                                 NULL,
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    135,
                                 130,
                                 50,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hwndStatic7=CreateWindowEx(0,WC_STATIC,
                                 ("Résultat:"),
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    190,
                                 130,
                                 80,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
    hresultat= CreateWindowEx(0,WC_STATIC,
                                 NULL,
                                    WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP ,
                                    275,
                                 130,
                                 80,
                                 20,
                                 cadre,
                                 NULL
                                 ,
                                 hThisInstance,
                                 NULL);
        ListView_SetExtendedListViewStyle(hListView2,LVS_EX_HEADERDRAGDROP|LVS_SORTDESCENDING|
                                          LVS_EX_FULLROWSELECT|LVS_EX_UNDERLINEHOT|
                                          LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
        hFont=CreateFontA( 20, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);

        SendMessage (hListView2, WM_SETFONT,hFont , TRUE);
        //SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
        LVCOLUMN lvc = { 0 };
        lvc.mask = LVCF_TEXT | LVCF_WIDTH  | LVCF_FMT;
        lvc.fmt  = LVCFMT_CENTER;
        lvc.iSubItem = 0;
        lvc.cx       = 100;
        lvc.pszText  = TEXT("Matiere");
        ListView_InsertColumn(hListView2, 0, &lvc);


        lvc.iSubItem = 1;
        lvc.cx       = 75;
        lvc.pszText  = TEXT("DS");
        ListView_InsertColumn(hListView2, 1, &lvc);
        //lvc.fmt  = LVCFMT_LEFT;
        lvc.iSubItem = 2;
        lvc.cx       = 75;
        lvc.pszText  = TEXT("EX");
        ListView_InsertColumn(hListView2, 2, &lvc);

        lvc.iSubItem = 3;
        lvc.cx       = 150;
        lvc.pszText  = TEXT("Moyenne");
        ListView_InsertColumn(hListView2, 3, &lvc);


}
void fill_etudiant(etudiant * q){
    ListView_DeleteAllItems(hListView2);
    char Temp[255]="";
    char temp1[255]="";
    char temp2[255]="";

    LVITEM   lv  = { 0 };
    matiere *r;
        for (r=q->tn;r<q->tn+q->nbmat;r++){
            int iItem;
            float moy;

            moy=(r->ds*0.3)+(r->ex*0.7);
            iItem=SendMessage(hListView2,LVM_GETITEMCOUNT,0,0);
            sprintf(Temp,"%.2f",r->ds);
            sprintf(temp1,"%.2f",r->ex);
            sprintf(temp2,"%.2f",moy);
            lv.iItem = iItem;
            ListView_InsertItem(hListView2, &lv);
            ListView_SetItemText(hListView2, iItem, 0, TEXT(r->nomm));
            ListView_SetItemText(hListView2, iItem, 1, TEXT(Temp));
            ListView_SetItemText(hListView2, iItem, 2, TEXT(temp1));
            ListView_SetItemText(hListView2, iItem, 3, TEXT(temp2));

        }



}
void fill_etudiant2(etudiant * q){
    char * ch[400];
    char * d[30];
    char *  r[30];
    hFont=CreateFontA( 30, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    if(q->moy>=10)
        sprintf(r,"ADMIS");
    else
        sprintf(r,"REFUSÉ");
    sprintf(d,"%d/%d/%d",q->dn.j,q->dn.m,q->dn.a);
    sprintf(ch,"%.2f",q->moy);
    //SetWindowText(hwndStatic3,(ch));
    SetWindowText(hname,(q->nom));
    SetWindowText(hprenom,(q->prenom));
    SetWindowText(hdate,(d));
    SetWindowText(hmoy,(ch));
    SetWindowText(hresultat,(r));
    //SendMessage(hwndStatic3,WM_SETFONT,hFont,TRUE);

}
void init_supp_note(HWND hwnd,char * c ,char *d,char *g, int id){
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|BS_GROUPBOX|BS_CENTER , 500, 100, 420,140, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);


     hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(d), WS_CHILD|WS_VISIBLE  ,
               60, 60, 195, 20, cadre, NULL, NULL, NULL);
    hwndStatic3 = CreateWindowEx(0,WC_STATIC ,(g), WS_CHILD|WS_VISIBLE  ,
               60, 90, 195, 20, cadre, NULL, NULL, NULL);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 60, 100, 20,
                                                 cadre, (HMENU)ID_EDIT, NULL, 0);
    edit2 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 90, 100, 20,
                                                 cadre, NULL, NULL, 0);
    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Supprimer", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 630, 230, 80, 20, hwnd, id, hThisInstance, 0);
    hCtrl0_8 = CreateWindowEx(0, WC_BUTTON, "Annuler", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 715, 230, 80, 20, hwnd, ID_ANNULEZ, hThisInstance, 0);
     hFont=CreateFontA( 18, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
     SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
      SendMessage (hCtrl0_8, WM_SETFONT,hFont , TRUE);
}
void init_supp(HWND hwnd,char * c ,char *d, int id){
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|BS_GROUPBOX|BS_CENTER , 500, 100, 420,120, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);


     hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(d), WS_CHILD|WS_VISIBLE  ,
               60, 60, 195, 20, cadre, NULL, NULL, NULL);

    edit = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 60, 100, 20,
                                                 cadre, (HMENU)ID_EDIT, NULL, 0);


    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Supprimer", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 630, 210, 80, 20, hwnd, id, hThisInstance, 0);
    hCtrl0_8 = CreateWindowEx(0, WC_BUTTON, "Annuler", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 715, 210, 80, 20, hwnd, ID_ANNULEZ, hThisInstance, 0);
     hFont=CreateFontA( 18, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
     SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
      SendMessage (hCtrl0_8, WM_SETFONT,hFont , TRUE);

}
void init_add_mat(HWND hwnd,char * c ,char *d, int id){
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|BS_GROUPBOX|BS_CENTER , 500, 100, 420,160, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);

     hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(d), WS_CHILD|WS_VISIBLE  ,
               60, 40, 195, 20, cadre, NULL, NULL, NULL);
    hwndStatic3 = CreateWindowEx(0,WC_STATIC ,("Donner le nom de Matière:"), WS_CHILD|WS_VISIBLE  ,
               60, 70, 195, 20, cadre, NULL, NULL, NULL);
    hwndStatic4 = CreateWindowEx(0,WC_STATIC ,("Donner le coefficient:"), WS_CHILD|WS_VISIBLE  ,
               60, 100, 195, 20, cadre, NULL, NULL, NULL);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 40, 100, 20,
                                                 cadre, (HMENU)ID_EDIT, NULL, 0);
    edit2 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 70, 100, 20,
                                                 cadre, (HMENU)NULL, NULL, 0);

    edit3 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 100, 100, 20,cadre,
                                                NULL,NULL,NULL);


    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Ajouter", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 630, 250, 80, 20, hwnd, id, hThisInstance, 0);
    hCtrl0_8 = CreateWindowEx(0, WC_BUTTON, "Annuler", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 715, 250, 80, 20, hwnd, ID_ANNULEZ, hThisInstance, 0);
     hFont=CreateFontA( 18, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
     SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
      SendMessage (hCtrl0_8, WM_SETFONT,hFont , TRUE);

}
void init_add_note(HWND hwnd,char * c ,char *d, int id){
    cadre = CreateWindowEx(0, WC_BUTTON, (c), WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|BS_GROUPBOX|BS_CENTER , 500, 100, 420,180, hwnd, NULL, NULL, 0);
    hFont=CreateFontA( 25, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
    SendMessage (cadre, WM_SETFONT,hFont , TRUE);

     hwndStatic2 = CreateWindowEx(0,WC_STATIC ,(d), WS_CHILD|WS_VISIBLE  ,
               60, 40, 195, 20, cadre, NULL, NULL, NULL);
    hwndStatic3 = CreateWindowEx(0,WC_STATIC ,("Donner le code de Matière:"), WS_CHILD|WS_VISIBLE  ,
               60, 70, 195, 20, cadre, NULL, NULL, NULL);
    hwndStatic4 = CreateWindowEx(0,WC_STATIC ,("Donner le Note DS:"), WS_CHILD|WS_VISIBLE  ,
               60, 100, 195, 20, cadre, NULL, NULL, NULL);
    hListView1 = CreateWindowEx(0,WC_STATIC ,("Donner le Note EX:"), WS_CHILD|WS_VISIBLE  ,
               60, 130, 195, 20, cadre, NULL, NULL, NULL);
    edit = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 40, 100, 20,
                                                 cadre, (HMENU)ID_EDIT, NULL, 0);
    edit2 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 70, 100, 20,
                                                 cadre, (HMENU)NULL, NULL, 0);

    edit3 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 100, 100, 20,cadre,
                                                NULL,NULL,NULL);
     edit4 = CreateWindowEx(WS_EX_ACCEPTFILES |
                                                WS_EX_STATICEDGE,
                                                WC_EDIT, (""), WS_VISIBLE |
                                                WS_CHILD | WS_TABSTOP |
                                                WS_BORDER | ES_AUTOHSCROLL, 260, 130, 100, 20,cadre,
                                                NULL,NULL,NULL);


    hCtrl0_6 = CreateWindowEx(0, WC_BUTTON, "Ajouter", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 630, 270, 80, 20, hwnd, id, hThisInstance, 0);
    hCtrl0_8 = CreateWindowEx(0, WC_BUTTON, "Annuler", WS_VISIBLE |
                                   WS_CHILD | WS_TABSTOP|0x00000001 , 715, 270, 80, 20, hwnd, ID_ANNULEZ, hThisInstance, 0);
     hFont=CreateFontA( 18, 0, 0, 0, FW_DONTCARE|FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
                          OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
     SendMessage (hCtrl0_6, WM_SETFONT,hFont , TRUE);
      SendMessage (hCtrl0_8, WM_SETFONT,hFont , TRUE);

}
///6 group 10 etudiants*//
///contre exemple *//
///coefficient le tableau matiere///
void Stealth()
{
 AllocConsole();
 stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(stealth,SW_HIDE);
}
void Stealth1()
{
 AllocConsole();
 stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(stealth,SW_NORMAL);
}


#endif // MAIN_C_INCLUDED
