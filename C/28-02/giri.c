main()
{
        char * ptr1 = "etirW  a hsaB tpircs taht setaerc a yrotcerid deman atad_pukcab dna sevom otni .ti edisnI siht ,yrotcerid etaerc a elif deman txt.atad dna dda emos txet ot .ti tsiL lla selif ni eht yrotcerid ni deliated tamrof dna ypoc txt.atad ot a wen elif deman .txt.pukcab_atad evoM txt.pukcab_atad ot rehtona redlof dellac .sevihcra hcraeS rof a cificeps drow edisni txt.atad dna kcehc sti elif .epyt yalpsiD sti ,tnetnoc pmud ti ni lamicedaxeh ,tamrof dna egnahc sti snoissimrep ot eb elbadaer yb .enoyreve yleruceS refsnart txt.atad ot a etomer .revres ,yllaniF eteled txt.pukcab_atad dna yalpsid eht tsom yltnecer desu sdnammoc";
        char * ptr2 = ptr1;
        char base;
        while(*ptr1 != '\0')
        {
                if(*ptr1 == ' ')
                {
                        base = (ptr1 - ptr2)-1;
                        for(int i=base;i>=0;i--)
                        {
                                printf("%c",*(ptr2+i));
                        }
                        ptr2 = ptr1;
                }
                ptr1++;
        }
        base = (ptr1 - ptr2)-1;
        for(int i=base;i>=0;i--)
        {
                printf("%c",*(ptr2+i));
        }
        ptr2 = ptr1;
        printf("\n");

}
