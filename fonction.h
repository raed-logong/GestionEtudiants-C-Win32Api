#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
            {
                char codemat[10];
                char nommat[30];
                float coef;
            }coefficient;

typedef struct
            {
                char num_mat[10];
                char nomm[30];
                float ds;
                float ex;
            }matiere;

typedef struct
            {
                int j,m,a;
            }date;

typedef struct
            {
                char code[10];
                char nom[20];
                char prenom[20];
                date dn;
                int nbmat;
                matiere *tn;
                float moy;
            }etudiant;
typedef struct
            {
                char codeg[10];
                int nb_et;
                etudiant *te;
            }groupe;

int saisie_taille(int *x)
{
    do
    {
        printf ("donner la taille : ");
        scanf("%d",x);
    } while(!(*x>=1));
}


/**Fonction de verification d'une chaine contenant des**/
/**caractères ou chiffres ou espaces*****/
int  verif1(char ch[])
{
    int i;
    char c;
    for(i=0;ch[i];i++)
        if(!((toupper(ch[i])>='A'&& toupper(ch[i])<='Z') || ch[i]=='0'|| ch[i]=='1'|| ch[i]=='2'|| ch[i]=='3'|| ch[i]=='4'|| ch[i]=='5'|| ch[i]=='6'
             || ch[i]=='7'|| ch[i]=='8'||ch[i]=='9' || ch[i]==' '))
            return 0;
    return 1;
}

/**Fonction de verification d'une chaine contenant des**/
/**caractères ou espaces*****/

int  verif2(char ch[])
{
    int i;
    char c;
    for(i=0;ch[i];i++)
        if(!(toupper(ch[i])>='A'&&toupper(ch[i])<='Z'||ch[i]==' '))
            return 0;

    return 1;
}
/**Fonction de verification d'une chaine contenant des**/
/**caractères ou chiffres*****/
int  verif3(char ch[])
{
    int i;
    char c;
    for(i=0;ch[i];i++)
        if(!((toupper(ch[i])>='A'&& toupper(ch[i])<='Z') || ch[i]=='0'|| ch[i]=='1'|| ch[i]=='2'|| ch[i]=='3'|| ch[i]=='4'|| ch[i]=='5'|| ch[i]=='6'
             || ch[i]=='7'|| ch[i]=='8'||ch[i]=='9'))
            return 0;

    return 1;
}

/**Validité d'une date**/
int valide(date d)
{

    int jmax;
    switch (d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: jmax=31; break;
        case 4:
        case 6:
        case 9:
        case 11: jmax=30; break;
        case 2: if (d.a%4==0&&d.a%100||d.a%400==0)
                    jmax=29;
                else jmax=28;
    }
    return d.j>0&&d.j<=jmax&&d.m>0&&d.m<=12&&d.a>=1900;
}
/**Recherche d'une matiere ds le tableau TC à partir du début**/
/**de tc jusqu'a la matiere dont son adresse < pc**/
int existe0(coefficient *tc , coefficient *pc,char x[])
{
    coefficient *p;
    for (p=tc;p<pc;p++)
        if(strcmp(p->codemat,x)==0)
            return 1;
    return 0;
}
/**Recherche d'une maitiere x dans tout le tableau TC:retourne une adresse**/
coefficient* existe1(coefficient *tc , char x[],int nbm)
{
    coefficient *pc;
    for (pc=tc;pc<tc+nbm;pc++)
        if(strcmp(pc->codemat,x)==0)
            return pc;
    return NULL;
}
/**Recherche d'un groupe ds le tableau tab_g à partir du début **/
/** de tab_g jusqu'a le groupe dont son adresse < pg **/
int existe2(groupe *tab_g ,groupe *pg, char *x)
{
    groupe *p;
    for (p=tab_g;p<pg;p++)
        if(strcmp(p->codeg,x)==0)
            return 1;
    return 0;
}

/**Recherche d'un etudiant ds le tableau tab_g à partir du début **/
/** de tab_g jusqu'a létudiant dont son adresse < pe **/
etudiant *existe3(groupe *tab_g,int ng,etudiant *pe, char x[])
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        for(q=p->te;q<pe;q++)
            if(strcmp(q->code,x)==0)
                return q;
    }
     return NULL;
}
int *existe33(groupe *tab_g,int ng, char x[])
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
            if(strcmp(p->codeg,x)==0)
                return 1;
    }
     return 0;
}
int *existe44(groupe *tab_g,int ng, char x[])
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        for(q=p->te;q<p->te+p->nb_et;q++)
            if(strcmp(q->code,x)==0)
                return 1;
    }
     return 0;
}
etudiant *existe100(groupe *tab_g,int ng,etudiant *pe, char x[],char c[])
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        if(strcmp(p->codeg,x)==0){
            for(q=p->te;q<pe;q++)
            {

                fflush(stdin);
                if(strcmp(q->code,c)==0)
                    return q;}}
        else
        {
            for(q=p->te;q<p->te+p->nb_et;q++)
                {
                    fflush(stdin);
                    if(strcmp(q->code,c)==0)
                    return q;}
        }
    }
     return NULL;
}
/**Recherche d'un groupe ds tout le tableau tab_g(Tableau de groupes)*/
groupe * recherche_groupe(groupe *tab_g ,int ng, char *x)
{
    groupe *p;
    for (p=tab_g;p<tab_g+ng;p++)
        if(strcmp(p->codeg,x)==0)
            return p;
    return NULL;
}
/**Recherche d'un etudiant ds un groupe donné **/
etudiant *recherche_et_groupe(groupe *pg, char x[])
{
    etudiant *q;
    for(q=pg->te;q<pg->nb_et;q++)
            if(strcmp(q->code,x)==0)
                return q;
     return NULL;
}
/**Recherche d'un etudiant ds tous les groupe **/
etudiant *recherche_etudiant(groupe *tab_g,int ng, char x[])
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        for(q=p->te;q<p->te+p->nb_et;q++)
            if(strcmp(q->code,x)==0)
                {
                    //printf("hey=%s",q->code);
                    return q;
                }
    }

     return NULL;
}
/**Recherche d'une matiere x ds un groupe donné(g)**/
/**et pour un etudiant donné(y) et pour une matiere donné x et <pr*/
int existe4( groupe *tab_g,char g[],int tg,char y[], matiere *pr,char x[])
{
    matiere *r;
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+tg;p++)
        if(strcmp(p->codeg,g)==0)
            for(q=p->te;q<p->te+p->nb_et;q++)
                if(strcmp(q->code,y)==0)
                {
                    for (r=q->tn;r<pr/*q->tn+q->nbmat*/;r++)
                        if(strcmp(r->num_mat,x)==0)
                            return 1;
                }
    return 0;

}

/*************************************************/
/**************************************************/
/**************************************************/

/**** Remplir le tableau TC****/
void remplir_coef(coefficient *tc,int nbm)
{
    coefficient *pc;
    for (pc=tc;pc<tc+nbm;pc++)
    {
        do
        {
            printf("Donner le code de la matiere %d :",pc-tc+1);
            fflush(stdin);
           gets(pc->codemat);
        }while(!(verif1(pc->codemat) && existe0(tc,pc,pc->codemat)==0));

        do
        {
            printf("Donner le nom de la matiere %d :",pc-tc+1);
            fflush(stdin);
            gets(pc->nommat);
        }while(!(verif1(pc->nommat)));
        do
        {
            printf("Donner le coefficient de la matiere %d :",pc-tc+1);
            fflush(stdin);
            scanf("%f",&pc->coef);
        }while(!(pc->coef>0));

    }
}

/**Afficher les matieres avec leurs coefficient**/
void affiche_matiere(coefficient *tc,int nbm)
{
    coefficient *pc;
    for (pc=tc;pc<tc+nbm;pc++)
        printf("%s\t%s\t%.2f\n",pc->codemat,pc->nommat,pc->coef);
}

/*************************************************/
/**************************************************/
/**************************************************/

/******ENREGISTREMENT du TC DANS UN FICHIER*****/
void enregistrement(coefficient *tc,int nbm,char * nomFichier)
{
    coefficient *pc;
    FILE *fp;
    fp=fopen(nomFichier,"w");
    fprintf(fp,"%d\n",nbm); // sauvegarder la taille de tablau
    for(pc=tc;pc<tc+nbm;pc++)
    {
        fprintf(fp,"|%s|%s|%.2f|\n",pc->codemat,pc->nommat,pc->coef);
    }
    fclose(fp);
    printf ("\nEnregistrement du tableau dans le fichier %s \n",nomFichier);
}

int construction(char *ligne,int pos,char s,char *ch)
{
    int i,j;
    for(i=pos,j=0;ligne[i]!=s;i++)
            ch[j++]=ligne[i];
        ch[j]='\0';
    //puts(ch);
    return i+1;
}
/*****RECUPERATION D'UN FICHIER ---> TABLEAU TC********/
coefficient *recuperation (int *nbm, char *nomFichier)
{

    FILE *fp;
    coefficient *pc,*tc;
    int x,nb=0;
    int pos,i=0;
    char ligne[300];
    char ch[30];
    fp=fopen(nomFichier,"r");
    if(fp!=NULL)
    {
        fscanf(fp,"%d\n",&nb);
        if(nb)
        {
            tc=(coefficient*)malloc(nb*sizeof(coefficient));
            for(pc=tc;pc<tc+nb;pc++)
            {
                fgets(ligne,300,fp);
                pos=construction(ligne,0,'|',ch);
                pos=construction(ligne,pos,'|',pc->codemat);
                pos=construction(ligne,pos,'|',pc->nommat);
                pos=construction(ligne,pos,'|',ch);
                pc->coef=atof(ch);
            }
        }

    }
    else
        printf("\n Fichier vide \n");
    *nbm=nb;
    return tc;
}

/*************************************************/
/**************************************************/
/**************************************************/

/**Remplir le tableau tab_g avec ng : nb groupes,***/
/**tc:tableau de coefficients et nbm:nb de matieres du tableau tc**/
void remplir(groupe *tab_g,int ng,coefficient *tc ,int nbm)
{
    groupe *p;
    etudiant *q;
    matiere *r;
    coefficient *pc;
    int ne;
    float sc,s;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        printf("Groupe %d\n",p-tab_g+1);
        do
        {
            printf("Donner le code du groupe:");
            fflush(stdin);
            gets(p->codeg);
        }while(!(verif3(p->codeg) && existe2(tab_g,p,p->codeg)==0));
        printf("saisie nb d'etudiant du goupe %d\n",p-tab_g+1);
        saisie_taille(&ne);
        p->nb_et=ne;
        p->te=malloc(ne*sizeof(etudiant));
        for(q=p->te;q<p->te+ne;q++)
        {
            printf("etudiant %d du goupe %d\n",q-p->te+1,p-tab_g+1);
            do
            {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(q->code);
            }while(!(verif1(q->code) && existe100(tab_g,ng,q,p->codeg,q->code)==NULL));

            do
            {
                printf("Donner le nom de l'etudiant:");
                fflush(stdin);
                gets(q->nom);
            }while(!(verif2(q->nom)));
            do
            {
                printf("Donner le prenom de l'etudiant:");
                fflush(stdin);
                gets(q->prenom);
            }while(!(verif2(q->prenom)));
            do
            {
            printf("  Donner la date de naissance sous la forme jj/mm/aaaa : ");
            scanf("%d/%d/%d",&q->dn.j,&q->dn.m,&q->dn.a);
            }while(!(valide(q->dn)==1));
            do
            {
                 printf("Donner le nobre de matieres:");
                fflush(stdin);
                scanf("%d",&q->nbmat);
            }while(!(q->nbmat<=nbm));

            q->tn =(matiere*)malloc((q->nbmat)*sizeof(matiere));
            for (sc=0,s=0,r=q->tn;r<q->tn+q->nbmat;r++)
            {
                do
                {
                    printf("Donner le code de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    gets(r->num_mat);
                    pc=existe1(tc,r->num_mat,nbm);
                }while(!(pc!=NULL  && existe4(tab_g,p->codeg,ng,q->code,r,r->num_mat)==0));
                strcpy(r->nomm,pc->nommat);
                do
                {
                    printf("Donner la note DS de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ds);
                }while(!(r->ds>=0 && r->ds<=20));
               do
                {
                    printf("Donner la note EX de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ex);
                }while(!(r->ex>=0 && r->ex<=20));
                sc=sc+pc->coef;
                s=s+(r->ds*0.3 + r->ex*0.7)*pc->coef;
            }
            q->moy= s/sc;
        }
     }
}
/**Fonction affiche : chaqque groupe contient un ensemble d'étudiants,**/
/** et un étudiant cotient un ensemble de matières**/
void affiche_tab(groupe *tab_g,int ng)
{
    groupe *p;
    etudiant *q;
    matiere *r;
    int ne;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        printf("%s\t%d\n",p->codeg,p->nb_et);
        for(q=p->te;q<p->te+p->nb_et;q++)
        {
            printf("\t%s\t%s\t%s\t%d/%d/%d\t%.2f\n",q->code,q->nom,q->prenom,q->dn.j,q->dn.m,q->dn.a,q->moy);
            for (r=q->tn;r<q->tn+q->nbmat;r++)
                printf("\t\t%s\t%s\t%.2f\t%.2f\n",r->num_mat,r->nomm,r->ds,r->ex);

        }

        printf("\n");
    }
}
/*************************************************/
/**************************************************/
/**************************************************/

/******ENREGISTREMENT du TAB_G DANS UN FICHIER*****/
void enregistrement_etud(groupe *tab_g,int ng, char * nomFichier)
{
    groupe *p;
    etudiant *q;
    matiere *r;
    FILE *fp;
    fp=fopen(nomFichier,"w");
    fprintf(fp,"%d\n",ng);
    for(p=tab_g;p<tab_g+ng;p++)
    {
        fprintf(fp,"%s %d\n",p->codeg,p->nb_et);
        for(q=p->te;q<p->te+p->nb_et;q++)
         {
            fprintf(fp,"|%s|%s|%s|%d/%d/%d|%d",q->code,q->nom,q->prenom,q->dn.j,q->dn.m,q->dn.a,q->nbmat);
            for (r=q->tn;r<q->tn+q->nbmat;r++)
            {
                fprintf(fp,"|%s|%s|%.2f|%.2f",r->num_mat,r->nomm,r->ds,r->ex);
            }
            fprintf(fp,"|%.2f|\n",q->moy);
         }
    }

    fclose(fp);
    printf ("\nEnregistrement du tableau dans le fichier %s \n",nomFichier);
}
/*****RECUPERATION D'UN FICHIER ---> TABLEAU tab_g********/

groupe* recuperation_etud (int *ng ,char *nomFichier)
{

    FILE *fp;
    groupe *p,*tab_g;
    etudiant *q,e,*pe;
    matiere *r,m;

    int pos,i=0,j,x,y,n=0;
    char ligne[500];
    char ch[30];
    char etape[30];

    fp=fopen(nomFichier,"r");
    if(fp!=NULL)
    {
        fscanf(fp,"%d\n",&n);
        tab_g=(groupe*)malloc(n*sizeof(groupe));
        for(p=tab_g;p<tab_g+n;p++)
        {
            fscanf(fp,"%s %d\n",&p->codeg,&p->nb_et);
            p->te=(etudiant*)malloc((p->nb_et)*sizeof(etudiant));
            for(q=p->te;q<p->te+(p->nb_et);q++)
            {
                fgets(ligne,500,fp);
                pos=construction(ligne,1,'|',q->code);
                pos=construction(ligne,pos,'|',q->nom);
                pos=construction(ligne,pos,'|',q->prenom);
                pos=construction(ligne,pos,'/',ch);
                q->dn.j=atoi(ch);
                pos=construction(ligne,pos,'/',ch);
                q->dn.m=atoi(ch);
                pos=construction(ligne,pos,'|',ch);
                q->dn.a=atoi(ch);
                pos=construction(ligne,pos,'|',ch);
                q->nbmat=atoi(ch);
                q->tn =(matiere*)malloc((q->nbmat)*sizeof(matiere));
                for (r=q->tn;r<q->tn+q->nbmat;r++)
                {
                    pos=construction(ligne,pos,'|',r->num_mat);
                    pos=construction(ligne,pos,'|',r->nomm);
                    pos=construction(ligne,pos,'|',ch);
                    r->ds=atof(ch);
                    pos=construction(ligne,pos,'|',ch);
                    r->ex=atof(ch);
                }
                pos=construction(ligne,pos,'|',etape);
                q->moy=atof(etape);
            }
         }
    }
    else
        printf("\n Fichier vide \n");
    fclose(fp);
    *ng=n;
    return tab_g;
}
/*************************************************/
/**************************************************/
/**************************************************/

/**Saisir et retourner une matiere**/
coefficient saisie_matiere(coefficient *tc ,int nbm)
{
    coefficient m;
    do
    {
        printf("Donner le code de la matiere :");
        fflush(stdin);
        gets(m.codemat);
    }while(!(verif1(m.codemat) && existe1(tc,m.codemat,nbm)==NULL));

    do
    {
        printf("Donner le nom de la matiere  :");
        fflush(stdin);
        gets(m.nommat);
    }while(!(verif1(m.nommat)));
    do
    {
        printf("Donner le coefficient de la matiere :");
        fflush(stdin);
        scanf("%f",&m.coef);
    }while(!(m.coef>0));
    return m;
}
coefficient saisie_matiere2(char code [],char nom [],float cof)
{
    coefficient m;
    /*do
    {
        printf("Donner le code de la matiere :");
        fflush(stdin);
        gets(m.codemat);
    }while(!(verif1(m.codemat) && existe1(tc,m.codemat,nbm)==NULL));*/
    strcpy(m.codemat,code);

    /*do
    {
        printf("Donner le nom de la matiere  :");
        fflush(stdin);
        gets(m.nommat);
    }while(!(verif1(m.nommat)));*/
    strcpy(m.nommat,nom);
    m.coef=cof;
    return m;
}
/*************************************************/
/**************************************************/
/**************************************************/
/** saisir et retourner un groupe**/
int check(groupe p,etudiant *pe,char c[]){
    etudiant *q;
    for(q=p.te;q<pe;q++)
    {
        if(strcmp(c,q->code)==0)
            return 1;
    }
    return 0;


}
groupe saisie_groupe(groupe *tab_g,int ng,coefficient *tc ,int nbm){
    groupe p;
    etudiant *q;
    matiere *r;
    coefficient *pc;
    int ne;
    float sc,s;
    do
        {
            printf("Donner le code du groupe:");
            fflush(stdin);
            gets(p.codeg);
        }while(!(verif3(p.codeg) && existegroupe(tab_g,ng,p.codeg)==0));
        printf("saisie nb d'etudiant du goupe %d\n",ng+1);
        saisie_taille(&ne);
        p.nb_et=ne;
        p.te=malloc(ne*sizeof(etudiant));
        for(q=p.te;q<p.te+ne;q++)
        {
            printf("etudiant %d du goupe %d\n",q-p.te+1,ng+1);
            do
            {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(q->code);
            }while(!(verif1(q->code) && existeetudiant(tab_g,ng,q->code)==0&& check(p,q,q->code)==0));

            do
            {
                printf("Donner le nom de l'etudiant:");
                fflush(stdin);
                gets(q->nom);
            }while(!(verif2(q->nom)));
            do
            {
                printf("Donner le prenom de l'etudiant:");
                fflush(stdin);
                gets(q->prenom);
            }while(!(verif2(q->prenom)));
            do
            {
            printf("  Donner la date de naissance sous la forme jj/mm/aaaa : ");
            scanf("%d/%d/%d",&q->dn.j,&q->dn.m,&q->dn.a);
            }while(!(valide(q->dn)==1));
            do
            {
                 printf("Donner le nobre de matieres:");
                fflush(stdin);
                scanf("%d",&q->nbmat);
            }while(!(q->nbmat<=nbm));

            q->tn =(matiere*)malloc((q->nbmat)*sizeof(matiere));
            for (sc=0,s=0,r=q->tn;r<q->tn+q->nbmat;r++)
            {
                do
                {
                    printf("Donner le code de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    gets(r->num_mat);
                    pc=existe1(tc,r->num_mat,nbm);
                }while(!(pc!=NULL  && existe4(tab_g,p.codeg,ng,q->code,r,r->num_mat)==0));
                strcpy(r->nomm,pc->nommat);
                do
                {
                    printf("Donner la note DS de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ds);
                }while(!(r->ds>=0 && r->ds<=20));
               do
                {
                    printf("Donner la note EX de la matiere %d :",r-q->tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ex);
                }while(!(r->ex>=0 && r->ex<=20));
                sc=sc+pc->coef;
                s=s+(r->ds*0.3 + r->ex*0.7)*pc->coef;
            }
            q->moy= s/sc;
        }
    return p;
}
/**Saisir et retourner un etudiant **/
etudiant saisie_etudiant (groupe *tab_g,int ng,coefficient *tc ,int nbm,char *x){
    etudiant q;
    float sc,s;
    matiere *r;
    coefficient *pc;
            do
            {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(q.code);
            }while(!(verif1(q.code) && existeetudiant(tab_g,ng,q.code)==0));

            do
            {
                printf("Donner le nom de l'etudiant:");
                fflush(stdin);
                gets(q.nom);
            }while(!(verif2(q.nom)));
            do
            {
                printf("Donner le prenom de l'etudiant:");
                fflush(stdin);
                gets(q.prenom);
            }while(!(verif2(q.prenom)));
            do
            {
            printf("  Donner la date de naissance sous la forme jj/mm/aaaa : ");
            scanf("%d/%d/%d",&q.dn.j,&q.dn.m,&q.dn.a);
            }while(!(valide(q.dn)==1));
            do
            {
                 printf("Donner le nobre de matieres:");
                fflush(stdin);
                scanf("%d",&q.nbmat);
            }while(!(q.nbmat<=nbm));

            q.tn =(matiere*)malloc((q.nbmat)*sizeof(matiere));
            for (sc=0,s=0,r=q.tn;r<q.tn+q.nbmat;r++)
            {
                do
                {
                    printf("Donner le code de la matiere %d :",r-q.tn+1);
                    fflush(stdin);
                    gets(r->num_mat);
                    pc=existe1(tc,r->num_mat,nbm);
                }while(!(pc!=NULL  && existe4(tab_g,x,ng,q.code,r,r->num_mat)==0));
                strcpy(r->nomm,pc->nommat);
                do
                {
                    printf("Donner la note DS de la matiere %d :",r-q.tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ds);
                }while(!(r->ds>=0 && r->ds<=20));
               do
                {
                    printf("Donner la note EX de la matiere %d :",r-q.tn+1);
                    fflush(stdin);
                    scanf("%f",&r->ex);
                }while(!(r->ex>=0 && r->ex<=20));
                sc=sc+pc->coef;
                s=s+(r->ds*0.3 + r->ex*0.7)*pc->coef;
            }
            q.moy= s/sc;
        return q;
}
/**recherche d'une note a un etudiant donnée**/
int existe5( groupe *tab_g,int tg,char y[],char *x)
{
    matiere *r;
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+tg;p++)
            for(q=p->te;q<p->te+p->nb_et;q++)
                if(strcmp(q->code,y)==0)
                {
                    for (r=q->tn;r<q->tn+q->nbmat;r++)
                        if(strcmp(r->num_mat,x)==0)
                            return 1;
                }
    return 0;

}
/**saisir et retourner une note**/
matiere saisie_note(groupe *tab_g,int ng,coefficient *tc ,int nbm,char *x){
    matiere r;
    coefficient *pc;
    do
                {
                    printf("Donner le code de la matiere  :");
                    fflush(stdin);
                    gets(r.num_mat);
                    pc=existe1(tc,r.num_mat,nbm);
                }while(!(pc!=NULL  && existe5(tab_g,ng,x,r.num_mat)==0));
                strcpy(r.nomm,pc->nommat);
    do
                {
                    printf("Donner la note DS de la matiere :");
                    fflush(stdin);
                    scanf("%f",&r.ds);
                }while(!(r.ds>=0 && r.ds<=20));
    do
                {
                    printf("Donner la note EX de la matiere  :");
                    fflush(stdin);
                    scanf("%f",&r.ex);
                }while(!(r.ex>=0 && r.ex<=20));
    return r;
}

/**Aouter un matière dans le tableau tc**/
coefficient* ajoutmatiere(coefficient *tc ,int *nbm)
{
    coefficient *p=tc;

    p= realloc (p,((*nbm)+1)*sizeof(coefficient));
    *(p+(*nbm))=saisie_matiere(p,(*nbm));
    tc=p;

    //enregistrement(tc,nbm,"coeficient.txt");

    (*nbm)=(*nbm)+1;
    return p;
}
coefficient* ajoutmatiere2(coefficient *tc ,int *nbm,coefficient k)
{
    coefficient *p=tc;

    p= realloc (p,((*nbm)+1)*sizeof(coefficient));
    *(p+(*nbm))=k;
    tc=p;

    //enregistrement(tc,nbm,"coeficient.txt");

    (*nbm)=(*nbm)+1;
    return p;
}
/**ajouter un groupe au tableau tab_g**/
groupe* ajoutergroupe(groupe *tab_g,int *ng,coefficient *tc ,int nbm){

    int n=(*ng);
    groupe *p=tab_g;
    groupe g=saisie_groupe(tab_g,*ng,tc,nbm);
    p= realloc (p,(n+1)*sizeof(groupe));
    *(p+n)=g;
    (*ng)=n+1;
    return p;

}
/** ajouter un etudiant a un groupe donner**/
groupe * ajouteretudiant(groupe *tab_g,int ng,coefficient *tc ,int nbm){
    char x[30];

    int ne;
    float sc,s;
    do
        {
            printf("Donner le code du groupe:");
            fflush(stdin);
            gets(x);
        }while(!(verif3(x) && existegroupe(tab_g,ng,x)==1));
    groupe *p=recherche_groupe(tab_g,ng,x);
    etudiant *q=p->te;

    etudiant e=saisie_etudiant(tab_g,ng,tc,nbm,x);
    q= realloc (q,(p->nb_et+1)*sizeof(etudiant));
    *(q+p->nb_et)=e;
    p->nb_et=p->nb_et+1;
    p->te=q;
    return tab_g;



}
/**calculer moyenne d'un etudiant donner**/
float moyenne(etudiant *q,coefficient *tc , int nbm){

    float sc,s;
    matiere *r;
    coefficient *pc;
    if (q->nbmat==0){
        return 0;
    }
    for (sc=0,s=0,r=q->tn;r<q->tn+q->nbmat;r++)
            {
                fflush(stdin);
                pc=existe1(tc,r->num_mat,nbm);
                sc=sc+pc->coef;
                fflush(stdin);
                s=s+(r->ds*0.3 + r->ex*0.7)*pc->coef;
            }

    return (s/sc);
}
/**ajouter une note a un etudiant donner**/
groupe* ajouternote(groupe *tab_g,int ng,coefficient *tc ,int nbm){
    char x[30];
    do
            {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(x);
            }while(!(verif1(x) && recherche_etudiant(tab_g,ng,x)!=NULL));
    etudiant *q=recherche_etudiant(tab_g,ng,x);
    matiere m=saisie_note(tab_g,ng,tc,nbm,q->code);
    matiere *r=q->tn;
    r= realloc (r,(q->nbmat+1)*sizeof(etudiant));
    *(r+q->nbmat)=m;
    fflush(stdin);
    q->nbmat=q->nbmat+1;
    fflush(stdin);
    q->tn=r;
    fflush(stdin);
    q->moy=moyenne(q,tc,nbm);
    //printf("m=%.2f",q->moy);
    fflush(stdin);
    return tab_g;

}
groupe* ajouternote2(groupe *tab_g,int ng,coefficient *tc ,int nbm,char x[],matiere m){
//    char x[30];
    /*do
            {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(x);
            }while(!(verif1(x) && recherche_etudiant(tab_g,ng,x)!=NULL));*/
    etudiant *q=recherche_etudiant(tab_g,ng,x);
    //matiere m=saisie_note(tab_g,ng,tc,nbm,q->code);
    matiere *r=q->tn;
    r= realloc (r,(q->nbmat+1)*sizeof(etudiant));
    *(r+q->nbmat)=m;
    fflush(stdin);
    q->nbmat=q->nbmat+1;
    fflush(stdin);
    q->tn=r;
    fflush(stdin);
    q->moy=moyenne(q,tc,nbm);
    //printf("m=%.2f",q->moy);
    fflush(stdin);
    return tab_g;

}
groupe* add(groupe* tab_g,int i,groupe * g){
    groupe *p=tab_g+i;
    int j=atoi(g->codeg);
    itoa(j,p->codeg,10);

    p->nb_et=g->nb_et;
    p->te=g->te;

    return tab_g;




}
etudiant *add_etudiant(etudiant *q,int i,etudiant * e)
{
    etudiant *p=q+i;
    int j=atoi(e->code);
    itoa(j,p->code,10);
    p->dn.a=e->dn.a;
    p->dn.m=e->dn.m;
    p->dn.j=e->dn.j;
    p->moy=e->moy;
    p->nbmat=e->nbmat;
    strcpy(p->nom,e->nom);
    //printf("yo=%s\n",e->nom);
    //printf("yo=%s\n",p->nom);
    strcpy(p->prenom,e->prenom);
    p->tn=e->tn;
    return q;

}
/**supprimer groupe**/

groupe* supprimer_groupe(groupe *tab_g,int *ng){
    char x[30];
    do
        {
            printf("Donner le code du groupe:");
            fflush(stdin);
            gets(x);
        }while(!(verif3(x) && existegroupe(tab_g,(*ng),x)==1));
    groupe *h;
    h=(groupe*)malloc(((*ng)-1)*sizeof(groupe));
    groupe *p;
    int i =0;
    for(p=tab_g;p<tab_g+(*ng);p++){
        if(strcmp(p->codeg,x)!=0){
            h=add(h,i,p);
            i++;
            }
    }
    (*ng)=(*ng)-1;


    return h;
}
groupe* supprimer_groupe2(groupe *tab_g,int *ng,char x[]){
   /* char x[30];
    do
        {
            printf("Donner le code du groupe:");
            fflush(stdin);
            gets(x);
        }while(!(verif3(x) && existegroupe(tab_g,(*ng),x)==1));*/
    groupe *h;
    h=(groupe*)malloc(((*ng)-1)*sizeof(groupe));
    groupe *p,*p1;
    int i =0;
    for(p=tab_g,p1=h;p<tab_g+(*ng);p++){
        if(strcmp(p->codeg,x)!=0){
            //h=add(h,i,p);
            (*p1)=(*p);
            p1++;
            }
    }
    (*ng)=(*ng)-1;


    return h;
}
/**supprimer etudiant**/
groupe * supprimer_etudiant(groupe *tab_g,int ng){
    char x[30];
    char ch[30];
    do
        {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(x);
        }while(!(verif1(x) && existeetudiant(tab_g,ng,x)!=0));

    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++){
        for(q=p->te;q<p->te+p->nb_et;q++){
            if(strcmp(q->code,x)==0){
                strcpy(ch,p->codeg);

            }


        }
    }
    groupe *p1=recherche_groupe(tab_g,ng,ch);
    //printf("%s\n",p1->codeg);
    etudiant *e=recherche_etudiant(tab_g,ng,x);
    //printf("%s",e->nom);
    etudiant *n;
    n=(etudiant*)malloc(((p1->nb_et)-1)*sizeof(etudiant));
    //n=add_etudiant(n,0,e);
    //n=add_etudiant(n,1,e);
    int i=0,t=0;
    for(p=tab_g;p<tab_g+ng;p++){
        if(strcmp(p->codeg,p1->codeg)==0){

        for(q=p->te;q<p->te+p->nb_et;q++){
                ;
            if(strcmp(q->code,x)!=0){

                n=add_etudiant(n,i,q);
                i++;
                t++;
              }
        }

        }

    }

    etudiant *r;
    p1->te=n;
    p1->nb_et=p1->nb_et-1;
    return tab_g;
}
groupe * supprimer_etudiant2(groupe *tab_g,int ng,char x[]){
    //char x[30];
    char ch[30];
    /*do
        {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(x);
        }while(!(verif1(x) && existeetudiant(tab_g,ng,x)!=0));*/

    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++){
        for(q=p->te;q<p->te+p->nb_et;q++){
            if(strcmp(q->code,x)==0){
                strcpy(ch,p->codeg);

            }


        }
    }
    groupe *p1=recherche_groupe(tab_g,ng,ch);
    //printf("%s\n",p1->codeg);
    etudiant *e=recherche_etudiant(tab_g,ng,x);
    //printf("%s",e->nom);
    etudiant *n,*nn;
    n=(etudiant*)malloc(((p1->nb_et)-1)*sizeof(etudiant));
    //n=add_etudiant(n,0,e);
    //n=add_etudiant(n,1,e);
    int i=0,t=0;
    for(p=tab_g;p<tab_g+ng;p++){
        if(strcmp(p->codeg,p1->codeg)==0){

        for(q=p->te,nn=n;q<p->te+p->nb_et;q++){

            if(strcmp(q->code,x)!=0){

                //n=add_etudiant(n,i,q);
                (*nn)=(*q);
                nn++;
                t++;
              }
        }

        }

    }

    etudiant *r;
    p1->te=n;
    p1->nb_et=p1->nb_et-1;
    return tab_g;
}

groupe *supprimer_note(groupe *tab_g,int ng,coefficient* tc,int nbm)
{
    char x[30];
    char ch[30];
    do
        {
                printf("Donner le code de l'etudiant :");
                fflush(stdin);
                gets(x);
        }while(!(verif1(x) && existeetudiant(tab_g,ng,x)!=0));
    etudiant *e=recherche_etudiant(tab_g,ng,x);
     do
                {
                    printf("Donner le code de la matiere  :");
                    fflush(stdin);
                    gets(ch);
                    //pc=existe1(tc,r.num_mat,nbm);
                }while(! (verif1(ch) && existe5(tab_g,ng,x,ch)==1));
    etudiant *q,*q1;
    matiere *r,*r1,*r3;
    r1=(matiere*)malloc((e->nbmat-1)*sizeof(matiere));
    for(r=e->tn,r3=r1;r<e->tn+e->nbmat;r++){
                    if(strcmp(r->num_mat,ch)!=0){
                        (*r3)=(*r);
                        r3++;
                    }
                    else
                        printf("yes\n");


                }
    e->tn=r1;
    e->nbmat=e->nbmat-1;
    e->moy=moyenne(e,tc,nbm);
    //affiche_tab(tab_g,ng);
    return tab_g;



}
groupe *supprimer_note2(groupe *tab_g,int ng,coefficient* tc,int nbm,char x[30],char ch[30])
{

    etudiant *e=recherche_etudiant(tab_g,ng,x);

    etudiant *q,*q1;
    matiere *r,*r1,*r3;
    r1=(matiere*)malloc((e->nbmat-1)*sizeof(matiere));
    for(r=e->tn,r3=r1;r<e->tn+e->nbmat;r++){
                    if(strcmp(r->num_mat,ch)!=0){
                        (*r3)=(*r);
                        r3++;
                        fflush(stdin);
                    }
                    /*else
                        printf("yes\n");*/


                }
    e->tn=r1;
    e->nbmat=e->nbmat-1;
    e->moy=moyenne(e,tc,nbm);
    //affiche_tab(tab_g,ng);*/
    return tab_g;



}
coefficient* supprimer_matiere(coefficient* tc ,int * nbm,char ch[]){
    coefficient *c;
    //affiche_matiere(tc,(*nbm));
    int n=(*nbm);
    c=(coefficient*)malloc((n-1)*sizeof(coefficient));
    coefficient *p1,*p2;
    for(p1=tc,p2=c;p1<tc+n;p1++){
        if(strcmp(p1->codemat,ch)!=0){
            (*p2)=(*p1);
            p2++;
        }
    }
    (*nbm)=n-1;
    return c;

}
groupe *supprimer_note_mat(groupe *tab_g,int ng,coefficient* tc,int nbm,char x[30],char ch[30])
{
    int n=0;
    etudiant *e=recherche_etudiant(tab_g,ng,x);
    //etudiant *q,*q1;
    matiere *r,*r1,*r3;
   // printf("yes");
    r1=(matiere*)malloc((e->nbmat-1)*sizeof(matiere));
   // printf("done");
    for(r=e->tn,r3=r1;r<e->tn+e->nbmat;r++){
                    if(strcmp(r->num_mat,ch)!=0){
                        (*r3)=(*r);
                        r3++;
                        fflush(stdin);
                    }
                    else
                        printf("\n");
                }
    printf("sii\n");
    for (r=r1;r<r1+e->nbmat-1;r++){
        printf("pour etudiant %s %s \n",e->code,e->nom);
        printf("code=%s nom=%s|\n",r->num_mat,r->nomm);
    }
    if(strcmp(ch,"1")==0){
        e->tn=r1;
        }
    else
        e->tn=r1;

    e->nbmat=e->nbmat-1;
    fflush(stdin);
    e->moy=moyenne(e,tc,nbm);

    fflush(stdin);

    return tab_g;



}

groupe* supp_all_notes(groupe *tab_g,int ng,coefficient* tc,int nbm,char ch[])
{
    char *x[500];

    groupe *p;
    etudiant *q;
    matiere *r;
    groupe *p1,*p2,*p3;
    p1=(groupe*)malloc(ng*sizeof(groupe));
    for(p=tab_g,p2=p1;p<tab_g+ng;p++,p2++){
        (*p2)=(*p);

    }
    //printf("p1est \n");
    //affiche_tab(p1,ng);
    int j=0;
    for(p3=p1;p3<p1+ng;p3++){
        int ne=p3->nb_et;
        for(q=p3->te;q<p3->te+ne;q++){
                int nb=q->nbmat;

                for(r=q->tn;r<q->tn+nb;r++){

                    if(strcmp(r->num_mat,ch)==0){
                        //printf("code etudiant est=%s\n",q->code);
                        x[j]=q->code;
                        j++;
                       //tab_g=supprimer_note2(tab_g,ng,tc,nbm,q->code,ch);
                     //  printf("gg");

                          }
                    else
                        fflush(stdin);
                }


            }
    }
    int k;
    //printf("\n");

    for(k=0;k<j;k++){
        tab_g=supprimer_note2(tab_g,ng,tc,nbm,x[k],ch);
    }
    //affiche_tab(tab_g,ng);
    return tab_g;
    /*p1=supprimer_note_mat(tab_g,ng,tc,nbm,"2","2");
    p1=supprimer_note_mat(tab_g,ng,tc,nbm,"9","2");*/

}
saisie_pour_all_mat(coefficient *tc ,int nbm,char m[])
{
    //char m[30];

    do
    {
        printf("Donner le code de la matiere :");
        fflush(stdin);
        gets(m);
    }while(!(verif1(m) && existe1(tc,m,nbm)!=NULL));
    return m;
}
/*void main()
{
    groupe *tab_g;
    coefficient *tc;
    int ng,nbm;
    /********PARTIE1*******/
   /* printf("SAISIE NOMBRE MATIERES\n");
    saisie_taille(&nbm);
    tc=(coefficient*)malloc(nbm*sizeof(coefficient));
    remplir_coef(tc,nbm);
    printf("CONTENU DE TC\n");
    affiche_matiere(tc,nbm);
    enregistrement(tc,nbm,"coeficient.txt");*/

    /********PARTIE2*******/
    /*tc=recuperation(&nbm,"coeficient.txt");
    printf("CONTENU DE TC\n");
    affiche_matiere(tc,nbm);

    /********PARTIE3*******/
   /*tc=recuperation(&nbm,"coeficient.txt");
    printf("CONTENU DE TC\n");
    affiche_matiere(tc,nbm);
    printf("SAISIE NOMBRE GROUPES\n");
    saisie_taille(&ng);
    tab_g=(groupe*)malloc(ng*sizeof(groupe));
    remplir(tab_g,ng,tc,nbm);
    affiche_tab(tab_g,ng);
    enregistrement_etud(tab_g,ng,"groupe.txt");*/

     /********PARTIE4*******/
   /* tab_g=recuperation_etud(&ng,"groupe.txt");
    printf("CONTENU DE TG\n");
     affiche_tab(tab_g,ng);*/
 /********PARTIE5*******/
   /*nbm=ajoutmatiere(tc ,nbm);
    printf("\nCONTENU DE TC\n");
    affiche_matiere(tc,nbm);
    enregistrement(tc,nbm,"coeficient.txt");*/

    /*tc=recuperation(&nbm,"coeficient.txt");
    printf("\n fffff CONTENU DE TC\n");
    affiche_matiere(tc,nbm);
}
*/
float calcul_taux(groupe * tab_g,int ng){
    char * ch[400];
    groupe *p;
    etudiant *q;
    float n=0;;
    float m=0,pp=0;

     for(p=tab_g;p<tab_g+ng;p++)
     {
          for(q=p->te;q<p->te+p->nb_et;q++)
          {
                m=m+q->moy;
                if(q->moy>=10){
                    pp++;
                }
                n++;
          }
     }
     m=m/n;
     pp=(pp/n)*100;
    fflush(stdin);
    //printf("%.2f\n",pp);
    return pp;
     //strcat(ch,("Le Taux de Reussite est %.2f % et la moyenne generale =  %.2f",pp,m));

}
float calcul_taux_group(groupe * tab_g,int ng,char * x){
    char * ch[400];
    groupe *p;
    etudiant *q;
    float n=0;
    float m=0,pp=0;

     for(p=tab_g;p<tab_g+ng;p++)
     {
          if(strcmp(x,p->codeg)==0){
          for(q=p->te;q<p->te+p->nb_et;q++)
          {
                m=m+q->moy;
                if(q->moy>=10){
                    pp++;

                }
                n++;
          }
     }
     }
    //printf("%.2f",pp);
     pp=(pp/n)*100;

    //printf("%.2f\n",pp);
    return pp;
     //strcat(ch,("Le Taux de Reussite est %.2f % et la moyenne generale =  %.2f",pp,m));

}
float calcul_moy(groupe * tab_g,int ng){
    char * ch[400];
    groupe *p;
    etudiant *q;
    float n=0;
    float m=0,pp=0;

     for(p=tab_g;p<tab_g+ng;p++)
     {
          for(q=p->te;q<p->te+p->nb_et;q++)
          {
                m=m+q->moy;
                if(q->moy>=10){
                    pp++;
                }
                n++;
          }
     }
    m=m/n;
     /*pp=(pp/n)*100;
     fflush(stdin);*/
    //printf("%.2f",m);

    return m;
     //strcat(ch,("Le Taux de Reussite est %.2f % et la moyenne generale =  %.2f",pp,m));

}
float calcul_moy_group(groupe * tab_g,int ng,char * x){
    char * ch[400];
    groupe *p;
    etudiant *q;
    float n=0;
    float m=0,pp=0;

     for(p=tab_g;p<tab_g+ng;p++)
     {
          if(strcmp(x,p->codeg)==0){
          for(q=p->te;q<p->te+p->nb_et;q++)
          {
                m=m+q->moy;
                if(q->moy>=10){
                    pp++;

                }
            n++;
          }
     }
     }
     m=m/n;
     pp=(pp/n)*100;
    fflush(stdin);
    //printf("%.2f\n",pp);
    return m;
     //strcat(ch,("Le Taux de Reussite est %.2f % et la moyenne generale =  %.2f",pp,m));

}
void calcul_taux_moy(groupe * tab_g,int ng){
    char * ch[400];
    groupe *p;
    etudiant *q;
    float n;
    float m=0,pp=0;

     for(p=tab_g;p<tab_g+ng;p++)
     {
          for(q=p->te;q<p->te+p->nb_et;q++)
          {
                m=m+q->moy;
                if(q->moy>=10){
                    pp++;
                }
                n++;
          }
     }
     m=m/n;
     pp=(pp/n)*100;
    fflush(stdin);

    sprintf(ch,"Le Taux de Reussite est %.2f%% et la moyenne generale =  %.2f",pp,m);
    printf("%s",TEXT(ch));
    //return ch;
     //strcat(ch,("Le Taux de Reussite est %.2f % et la moyenne generale =  %.2f",pp,m));

}
/**Recherche d'un groupe ds le tableau tab_g à partir du début **/

int existegroupe(groupe *tab_g ,int ng, char *x)
{
    groupe *p;
    for (p=tab_g;p<tab_g+ng;p++)
        if(strcmp(p->codeg,x)==0)
            return 1;
    return 0;
}
int existeetudiant(groupe *tab_g,int ng,char *x)
{
    groupe *p;
    etudiant *q;
    for(p=tab_g;p<tab_g+ng;p++)
    {
        for(q=p->te;q<p->te+p->nb_et;q++){
            if(strcmp(q->code,x)==0)
                return 1;
        }
    }
     return 0;
}

groupe get_group(groupe * tab_g,int ng ,char *x){
    groupe *p;
    groupe g;
    for(p=tab_g;p<tab_g+ng;p++){

        if(strcmp(p->codeg,x)==0)
            g=(*p);
    }
    return g;

}
matiere * getmatiere(etudiant *e ,char x[]){
    matiere *r;
        for(r=e->tn;r<e->tn+e->nbmat;r++){
            if(strcmp(x,r->num_mat)==0){
                return r;
            }
        }
    return NULL;


}
void bulltein(etudiant * q,coefficient *tc , int nbm){
FILE *fp;
coefficient * pc;
matiere *r;
fp=fopen("bulltein.html","w");
fprintf(fp,"<html> <head>");
fprintf(fp,"<meta charset='utf-8' />");
fprintf(fp,"<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
fprintf(fp,"<title>Bulletin de note</title> \n <link href='style.css' rel='stylesheet' /></head>");

fprintf(fp,"<div ><h2 style='color:red'>Bulletin De note</h2></div>");
fprintf(fp,"<div class='container' >");
fprintf(fp,"<div class='topleft'>");
fprintf(fp,"<div><h2 style='text-align:left'>Code:%s</h2></div>",q->code);
fprintf(fp,"<div><h2 style='text-align:left'>Nom:%s</h2></div>",q->nom);
fprintf(fp,"<h2 style='text-align:left'>Prenom:%s</h2>",q->prenom);
fprintf(fp,"</div> <div class='topright' > <img src='poly.png' ></div></div></div><div>");

fprintf(fp,"</div> <div class='center'>");
fprintf(fp,"<table><thead>");
fprintf(fp,"<tr><td colspan='3'>Matiere </td>");
fprintf(fp,"<td rowspan='2'> Coefficient </td>");
fprintf(fp,"<td colspan='2'> Note </td>");
fprintf(fp,"<td rowspan='4'> Moyenne </td>");
fprintf(fp,"</tr>");
fprintf(fp,"<tr><td>Code </td><td colspan='2'> Nom </td><td> Ds </td><td> Ex </td></tr></thead>");
fprintf(fp,"<tbody>");
for(pc=tc;pc<tc+nbm;pc++){
    fprintf(fp,"<tr>");
    fprintf(fp,"<td>%s </td>",pc->codemat);
    fprintf(fp,"<td colspan='2'>%s </td>",pc->nommat);
    fprintf(fp,"<td> %.1f</td>",pc->coef);
    r=getmatiere(q,pc->codemat);
    if(r==NULL){
        fprintf(fp,"<td> Nan </td>");
        fprintf(fp,"<td> Nan </td>");
        fprintf(fp,"<td> Nan </td>");
    }
    else{
        fprintf(fp,"<td> %.2f </td>",r->ds);
        fprintf(fp,"<td> %.2f </td>",r->ex);
        fprintf(fp,"<td> %.2f </td>",(r->ds*0.3+r->ex*0.7));
    }
    fprintf(fp,"</tr>");
}
fprintf(fp,"</tbody><tfoot>");
fprintf(fp,"<tr>");
fprintf(fp,"<td colspan='6' class='footer'>Moyenne Generale</td>");
fprintf(fp,"<td colspan='3'>%.2f </td>",q->moy);

fprintf(fp,"</tr>");
fprintf(fp,"<tr>");
fprintf(fp,"<td colspan='6' class='footer'>Mention</td>");
if(q->moy>=10 &&q->moy<12){
    fprintf(fp,"<td colspan='3'>Passable</td>");
}
if(q->moy>=12 &&q->moy<14){
    fprintf(fp,"<td colspan='3'>Assez-Bien</td>");
}
if(q->moy>=14 &&q->moy<16){
    fprintf(fp,"<td colspan='3'>Bien</td>");
}
if(q->moy>=16){
    fprintf(fp,"<td colspan='3'>Tres Bien</td>");
}
if(q->moy<10){
    fprintf(fp,"<td colspan='3'></td>");
}
fprintf(fp,"</tr>");
fprintf(fp,"<tr>");
fprintf(fp,"<td colspan='6' class='footer'>Resultat</td>");
if(q->moy>=10)
    fprintf(fp,"<td colspan='3'>ADMIS</td>");
else
    fprintf(fp,"<td colspan='3'>REFUSE</td>");
fprintf(fp,"</tr>");
fprintf(fp,"</table></div></body></html>");





fclose(fp);
system("start bulltein.html");

}
int test_float(char * number) {

   // char *number = "5.53 garbanzo beans";
    char *foo;
    int ok=1;
    double d = strtod(number, &foo);
    if (foo == number) {
        return 0;;

    }
    else if (foo[strspn(foo, " \t\r\n")] != '\0') {
        return 0;
    }
    else {
        return 1;
    }
}
int test_num(char * ch)/**Tester si une chaine est numerique*/
{

    int i,ok=1;
    if((isdigit(ch[0])==0)&&(ch[0]!='-')&&(ch[0]!='+'))
    {
        ok=0;
        return ok;
    }
    for(i=1;i<strlen(ch);i++)
    {
        if(isdigit(ch[i])==0)
            {
                ok=0;
                break;
            }
    }
    return ok ;
}

#endif // FONCTION_H_INCLUDED

