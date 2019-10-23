#include "../include/arguments.h"


// print help menu.
void printHelp()
{
  std::cout << "\n* --imgdir <path> Specify directory where output images are written to.\n"
            << "* --maxgen <num> Number of generations to simulate\n"
            << "* --fps <num> Number of generations presented per second.\n"
            << "* --blocksize <num> Pixel size of a cell. Default = 5.\n"
            << "* --bkgcolor <color> Color name for the background. Default GREEN.\n"
            << "* --alivecolor <color> Color name for representing alive cells. Default RED.\n"
            << "* --outfile <filename> Write the text representation of the simulation to the given filename.\n\n"
            << "\x1b[96mAvailable colors are:\x1b[0m\n"
            << "BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n"
            << "GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n"
            << "WHITE YELLOW\n";
}


bool filename_verification( char const & filename )
{
    std::string aux = &filename;

    // verify .txt
    if(  aux[aux.length() - 1] == 't' )
    {
        if( aux[aux.length() - 2] == 'x' )
        {
            if( aux[aux.length() - 3] == 't')
            {
                if( aux[aux.length() - 4] == '.' )
                {
                    return true;
                }
            }
        }
    }

    // verify .dat
    if(  aux[aux.length() - 1] == 't' )
    {
        if( aux[aux.length() - 2] == 'a' )
        {
            if( aux[aux.length() - 3] == 'd')
            {
                if( aux[aux.length() - 4] == '.' )
                {
                    return true;
                }
            }
        }
    }
    
    return false;

}



bool processing_arguments( Options & arguments, int argc, char const *argv[] )
{
    if( argc < 2 ) // min arguments.
    {
        std::cout << "\x1b[31mToo few arguments!\x1b[0m\n\nAt least inform initial configuration filename!\n\n";
        std::cout << "\x1b[93mUsage\x1b[0m: glife [<options>] <input_cfg_file>\n"
             << "Simulation options:\n\t\x1b[92m./glife\x1b[0m --help to see the menu.\n";
        return false;
    }
    if( argc > 16 ) // max arguments.
    {
        std::cout << "\x1b[31mToo many arguments!\x1b[0m\n\n";
        std::cout << "\x1b[93mUsage\x1b[0m: glife [<options>] <input_cfg_file>\n"
             << "Simulation options:\n\t\x1b[92m./glife\x1b[0m --help to see the menu.\n";
    }
    if( ( argc == 2 ) and ( strcmp( argv[1], "--help" ) == 0 ) ) // print help menu.
    {
        printHelp();

        return true;
    }
    // verify if second argument is a valid file.
    if( ( argc == 2 ) and ( filename_verification( *argv[1] ) == true )  )
    {
        //read file function TODO.
    }
    else if( ( argc == 2 ) and ( filename_verification( *argv[1] ) == false )  )
    {
        std::cout << "\x1b[31mInvalid file!\x1b[0m\n\nplease, input a .txt or .dat file.\n";
        return false;
    }

    if( argc > 2 )
    {
        for( int i = 1; i < argc; i++ )
        {
            if( arguments.configFile == "" )
            {
                if( ( argv[i][0] != '-' ) and ( argv[i][1] != '-') ) // filtering options
                {
                    if( filename_verification( *argv[i] ) == true ) // verify a valid filename.
                    {
                        arguments.configFile = argv[i];
                    }
                    else if( ( filename_verification( *argv[i] ) == false ) and ( i == argc - 1 ) )
                    {
                        // non valid file.
                        std::cout << "\x1b[31mInvalid file!\x1b[0m\n\nplease, input a .txt or .dat file.\n";
                        return false;
                    }
                    else if( filename_verification( *argv[i] ) == false )
                    {
                        continue;
                    }
                }
            }

            if( strcmp( argv[i], "--imgdir" ) == 0 )
            {
                arguments.imgdirpath = argv[i+1];
            }

            if( strcmp( argv[i], "--maxgen" ) == 0 )
            {
                arguments.maxgen = atoi(argv[i+1]);
            }

            if( strcmp( argv[i], "--fps" ) == 0 )
            {
                arguments.fps = atoi(argv[i+1]);
            }

            if( strcmp( argv[i], "--blocksize" ) == 0 )
            {
                arguments.pixel_size = atoi( argv[i+1]);
            }

            if( strcmp( argv[i], "--bkgcolor" ) == 0 )
            {
                arguments.bkgcolor = argv[i+1];
            }

            if( strcmp( argv[i], "--alivecolor" ) == 0 )
            {
                arguments.alivecolor = argv[i+1];
            }

            if( strcmp( argv[i], "--outfile" ) == 0 )
            {
                arguments.outfile = argv[i+1];
                std::cout << "output file = " << arguments.outfile << "\n";
            }


        }
    }

    return true;
}






