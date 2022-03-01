// My headers
#include "../include/manipulators/csmanip.hpp"
#include "../include/progressbar/progress_bar.hpp"
#include "../include/progressbar/multi_progress_bar.hpp"
#include "../include/graphics/canvas.hpp"
#include "../include/graphics/plot_2D.hpp"

// STD headers
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

// Using namespaces
using namespace osm;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void col_sty()
{
    //====================================================
    //     CSMANIP FEATURES
    //====================================================
    cout << endl
         << "======================================================" << endl
         << "     COLORS                                           " << endl
         << "======================================================" << endl

         << feat( col, "black" ) << "This is a black string." << reset( "color" ) << endl
         << feat( col, "red" ) << "This is a red string." << reset( "color" ) << endl
         << feat( col, "green" ) << "This is a green string." << reset( "color" ) << endl
         << feat( col, "orange" ) << "This is an orange string." << reset( "color" ) << endl
         << feat( col, "blue" ) << "This is a blue string." << reset( "color" ) << endl
         << feat( col, "purple" ) << "This is a purple string." << reset( "color" ) << endl
         << feat( col, "cyan" ) << "This is a cyan string." << reset( "color" ) << endl
         << feat( col, "gray" ) << "This is a gray string." << reset( "color" ) << endl
         << feat( col, "dk gray" ) << "This is a dark gray string." << reset( "color" ) << endl
         << feat( col, "lt red" ) << "This is a light red string." << reset( "color" ) << endl
         << feat( col, "lt green" ) << "This is a light green string." << reset( "color" ) << endl
         << feat( col, "yellow" ) << "This is a yellow string." << reset( "color" ) << endl
         << feat( col, "lt blue" ) << "This is a light blue string." << reset( "color" ) << endl
         << feat( col, "lt purple" ) << "This is a light purple string." << reset( "color" ) << endl
         << feat( col, "lt cyan" ) << "This is a light cyan string." << reset( "color" ) << endl
         << feat( col, "white" ) << "This is a white string." << reset( "color" ) << endl;

    sleep_for( seconds( 2 ) );

    cout << endl
         << "======================================================" << endl
         << "     BOLD COLORS                                      " << endl
         << "======================================================" << endl
         << endl

         << feat( col, "bd black" ) << "This is a bold black string." << reset( "bd color" ) << endl
         << feat( col, "bd red" ) << "This is a bold red string." << reset( "bd color" ) << endl
         << feat( col, "bd green" ) << "This is a bold green string." << reset( "bd color" ) << endl
         << feat( col, "bd orange" ) << "This is a bold orange string." << reset( "bd color" ) << endl
         << feat( col, "bd blue" ) << "This is a bold blue string." << reset( "bd color" ) << endl
         << feat( col, "bd purple" ) << "This is a bold purple string." << reset( "bd color" ) << endl
         << feat( col, "bd cyan" ) << "This is a bold cyan string." << reset( "bd color" ) << endl
         << feat( col, "bd gray" ) << "This is a bold gray string." << reset( "bd color" ) << endl;

    sleep_for( seconds( 2 ) );

    cout << endl
         << "======================================================" << endl
         << "     BACKGROUND COLORS                                " << endl
         << "======================================================" << endl
         << endl

         << feat( col, "bg black" ) << "This is a background black string." << reset( "bg color" ) << endl
         << feat( col, "bg red" ) << "This is a background red string." << reset( "bg color" ) << endl
         << feat( col, "bg green" ) << "This is a background green string." << reset( "bg color" ) << endl
         << feat( col, "bg orange" ) << "This is a background orange string." << reset( "bg color" ) << endl
         << feat( col, "bg blue" ) << "This is a background blue string." << reset( "bg color" ) << endl
         << feat( col, "bg purple" ) << "This is a background purple string." << reset( "bg color" ) << endl
         << feat( col, "bg cyan" ) << "This is a background cyan string." << reset( "bg color" ) << endl
         << feat( col, "bg gray" ) << "This is a background gray string." << reset( "bg color" ) << endl
         << feat( col, "bg dk gray" ) << "This is a background dark gray string." << reset( "bg color" ) << endl
         << feat( col, "bg lt red" ) << "This is a background light red string." << reset( "bg color" ) << endl
         << feat( col, "bg lt green" ) << "This is a background light green string." << reset( "bg color" ) << endl
         << feat( col, "bg yellow" ) << "This is a background yellow string." << reset( "bg color" ) << endl
         << feat( col, "bg lt blue" ) << "This is a background light blue string." << reset( "bg color" ) << endl
         << feat( col, "bg lt purple" ) << "This is a background light purple string." << reset( "bg color" ) << endl
         << feat( col, "bg lt cyan" ) << "This is a background light cyan string." << reset( "bg color" ) << endl
         << feat( col, "bg white" ) << "This is a background white string." << reset( "bg color" ) << " <-(white)" << endl;

    sleep_for( seconds( 2 ) );

    cout << endl
         << "======================================================" << endl
         << "     STYLES                                           " << endl
         << "======================================================" << endl
         << endl

         << feat( sty, "bold" ) << "This is a bold string." << reset( "bd/ft" ) << endl
         << feat( sty, "faint" ) << "This is a faint string." << reset( "bd/ft" ) << endl
         << feat( sty, "italics" ) << "This is an italics string." << reset( "italics" ) << endl
         << feat( sty, "underlined" ) << "This is an underlined string." << reset( "underlined" ) << endl
         << feat( sty, "d-underlined" ) << "This is a doubly underlined string." << reset( "underlined" ) << endl
         << feat( sty, "inverse" ) << "This is an inverse string." << reset( "inverse" ) << endl
         << feat( sty, "invisible" ) << "This is an invisible string." << reset( "invisible" ) << "It was an invisible string." << endl
         << feat( sty, "crossed" ) << "This is a crossed-out string." << reset( "crossed" ) << endl
         << feat( sty, "blink" ) << "This is a blink string." << reset( "blink" ) << endl;

    cout << endl
         << "======================================================" << endl
         << "     MIXED                                           " << endl
         << "======================================================" << endl
         << endl

         << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" ) << endl
         << feat( sty, "italics" ) << feat( col, "blue" ) << "This is an italics blue string." << reset( "all" ) << endl
         << feat( sty, "faint" ) << feat( col, "orange" ) << "This is a faint orange string." << reset( "all" ) << endl;
    sleep_for( seconds( 2 ) );
}

void printer()
{
    //====================================================
    //     PRINTING FUNCTIONS FEATURES
    //====================================================
    cout << endl
         << "======================================================" << endl
         << "     PRINTING FUNCTIONS                                           " << endl
         << "======================================================" << endl;

    // Normal examples:
    print( cout, "This is the ", "\"printf\" ", "function for the normal output stream! ", 100, "% working!" );
    print( cerr, "This is the printf function for the stderr stream! ", "Managing errors is always important!" );
    print( clog, "Also writing in stdlog is important! ", feat( sty, "underlined" ), "Very important", reset( "underlined" ), "!" );
    //   print();

    // Writing on a file:
    ofstream file_stream;
    file_stream.open( "file.txt", ios::trunc );
    print( file_stream, "You can also write in a file! ", 1, 2, 3, 4.5, 7 );
    file_stream.close();
    print( "Text has been wrote to ", "file.txt ", "file!" );
}

//====================================================
//     PERCENTAGE BAR
//====================================================
void perc_bars()
{
    cout << endl
         << "======================================================" << endl
         << "     PERCENTAGE BARS                                    " << endl
         << "======================================================" << endl
         << endl;

    // Normal percentage bar.
    ProgressBar<int> percentage_bar;
    percentage_bar.setMin( 5 );
    percentage_bar.setMax( 46 );
    percentage_bar.setStyle( "indicator", "%" );

    cout << "This is a normal percentage bar: " << endl;
    for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        percentage_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    // Percentage bar with message and different style:
    ProgressBar<float> percentage_bar_2;
    percentage_bar_2.setMin( 1.2f );
    percentage_bar_2.setMax( 4.4f );
    percentage_bar_2.setMessage( "processing..." );
    percentage_bar_2.setStyle( "indicator", "/100" );

    cout << "This is a percentage bar with message and the /100 style: " << endl;
    for( float i = percentage_bar_2.getMin(); i < percentage_bar_2.getMax(); i += 0.1f )
    {
        sleep_for( milliseconds( 100 ) );
        percentage_bar_2.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    // Percentage bar with time consuming info:
    percentage_bar.resetMessage();
    percentage_bar.setStyle( "indicator", "%" );

    cout << "This is a percentage bar with time consuming info: " << endl;
    for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
    {
        percentage_bar.setBegin();
        sleep_for( milliseconds( 100 ) );
        percentage_bar.update( i );
        // Do some operations...
        percentage_bar.setEnd();
    }
    cout << endl
         << "Time needed to complete the previous loop: " << percentage_bar.getTime() << " ms." << endl
         << endl;

    // Percentage bar with estimated time left:
    percentage_bar.setMin( 2 );
    percentage_bar.setMax( 121 );
    percentage_bar.setRemainingTimeFlag( "on" );
    percentage_bar.resetRemainingTime();
    cout << "This is a percentage bar with time-remaining info: " << endl;
    for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        percentage_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;
}

//====================================================
//     LOADING BAR
//====================================================
void load_bars()
{
    cout << endl
         << "======================================================" << endl
         << "     LOADING BARS                                    " << endl
         << "======================================================" << endl
         << endl;

    ProgressBar<int> loading_bar;
    loading_bar.setMin( 3 );
    loading_bar.setMax( 25 );
    loading_bar.setStyle( "loader", "#" );
    loading_bar.setBrackets( "[", "]" );

    cout << "This is a normal loading bar: " << endl;
    for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        loading_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    // Loading bar with message:
    loading_bar.resetBrackets();
    loading_bar.setMessage( "processing..." );
    loading_bar.setBrackets( "{", "}" );

    cout << "This is a loading bar with message: " << endl;
    for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        loading_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    // Loading bar with time remaining info:
    loading_bar.setMin( 3 );
    loading_bar.setMax( 101 );
    loading_bar.resetMessage();
    loading_bar.setRemainingTimeFlag( "on" );
    loading_bar.resetRemainingTime();

    cout << "This is a loading bar with time-remaining info: " << endl;
    for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        loading_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;
}

//====================================================
//     MIXED BAR
//====================================================
void mixed_bars()
{
    cout << endl
         << "======================================================" << endl
         << "     FULL PROGRESS BARS                                    " << endl
         << "======================================================" << endl
         << endl;

    ProgressBar<float> mixed_bar;
    mixed_bar.setMin( 0.1f );
    mixed_bar.setMax( 3.8f );
    mixed_bar.setStyle( "complete", "%", "■" );
    mixed_bar.setBrackets( "[", "]" );
    mixed_bar.setMessage( "elaborating..." );

    cout << "This is a mixed progress bar: " << endl;
    for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
    {
        sleep_for( milliseconds( 100 ) );
        mixed_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    mixed_bar.setColor( "red" );
    mixed_bar.setRemainingTimeFlag( "on" );
    mixed_bar.resetRemainingTime();

    cout << "This is a mixed progress bar with color and time remaining info: " << endl;
    for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
    {
        sleep_for( milliseconds( 100 ) );
        mixed_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    mixed_bar.resetColor();
    mixed_bar.addStyle( "indicator", "|100" );
    mixed_bar.addStyle( "loader", ">" );
    mixed_bar.setStyle( "complete", "|100", ">" );
    mixed_bar.setRemainingTimeFlag( "off" );

    cout << "This is a mixed progress bar with two customized styles: " << endl;
    for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
    {
        sleep_for( milliseconds( 100 ) );
        mixed_bar.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;
}

//====================================================
//     MULTI BARS
//====================================================
void multi_bars()
{
    cout << endl
         << "======================================================" << endl
         << "     MULTI PROGRESS BARS                                    " << endl
         << "======================================================" << endl
         << endl;

    cout << "These are 3 progress bars printed simultaneously: " << endl
         << endl
         << endl;

    ProgressBar<int> prog_int;
    prog_int.setMin( 0 );
    prog_int.setMax( 60 );
    prog_int.setStyle( "complete", "%", "#" );
    prog_int.setBrackets( "[", "]" );
    prog_int.setMessage( "Installing..." );
    prog_int.setColor( "red" );

    ProgressBar<int> prog_int_2;
    prog_int_2.setMin( 5 );
    prog_int_2.setMax( 25 );
    prog_int_2.setStyle( "complete", "%", "■" );
    prog_int_2.setBrackets( "{", "}" );
    prog_int_2.setMessage( "Processing..." );
    prog_int_2.setColor( "purple" );

    ProgressBar<float> prog_float;
    prog_float.setMin( 0.1f );
    prog_float.setMax( 5.8f );
    prog_float.setStyle( "complete", "%", "#" );
    prog_float.setBrackets( "[", "]" );
    prog_float.setMessage( "Downloading..." );
    prog_float.setColor( "yellow" );

    auto bars = MultiProgressBar( prog_int, prog_int_2, prog_float );

    auto job1 = [ &bars, &prog_int ]()
    {
        for( int i = prog_int.getMin(); i < prog_int.getMax(); i++ )
        {
            bars.for_one( 0, updater {}, i );
            sleep_for( milliseconds( 100 ) );
        }
    };

    auto job2 = [ &bars, &prog_int_2 ]()
    {
        for( int i = prog_int_2.getMin(); i < prog_int_2.getMax(); i++ )
        {
            bars.for_one( 1, updater {}, i );
            sleep_for( milliseconds( 200 ) );
        }
    };

    auto job3 = [ &bars, &prog_float ]()
    {
        for( float i = prog_float.getMin(); i < prog_float.getMax(); i += 0.1f )
        {
            bars.for_one( 2, updater {}, i );
            sleep_for( milliseconds( 60 ) );
        }
    };

    thread first_job( job1 );
    thread second_job( job2 );
    thread third_job( job3 );

    first_job.join();
    second_job.join();
    third_job.join();

    cout << endl
         << endl
         << endl;
}

//====================================================
//     PROGRESS SPINNER
//====================================================
void progress_spinner()
{
    cout << endl
         << "======================================================" << endl
         << "     PROGRESS SPINNER                                    " << endl
         << "======================================================" << endl
         << endl;

    // Integer progress spinner.
    ProgressBar<int> spinner;
    spinner.setMin( 2 );
    spinner.setMax( 33 );
    spinner.setStyle( "spinner", "/-\\|" );

    cout << "This is a progress spinner: " << endl;
    for( int i = spinner.getMin(); i < spinner.getMax(); i++ )
    {
        sleep_for( milliseconds( 100 ) );
        spinner.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;

    // Float progress spinner.
    ProgressBar<float> spinner_float;
    spinner_float.setMin( 2.3f );
    spinner_float.setMax( 6.7f );
    spinner_float.setColor( "lt blue" );
    spinner_float.addStyle( "spinner", "|/_\\" );
    spinner_float.setStyle( "spinner", "|/_\\" );
    spinner_float.setMessage( "elaborating data..." );

    cout << "This is another progress spinner: " << endl;
    for( float i = spinner_float.getMin(); i < spinner_float.getMax(); i += 0.1f )
    {
        sleep_for( milliseconds( 100 ) );
        spinner_float.update( i );
        // Do some operations...
    }
    cout << endl
         << endl;
}

//====================================================
//     2D TERMINAL GRAPHICS
//====================================================
void canvas_2d()
{
    cout << endl
         << "======================================================" << endl
         << "     CANVAS                                    " << endl
         << "======================================================" << endl
         << endl;

    cout << "Display an animation in a canvas" << endl;
    Canvas canvas( 10, 10 );
    canvas.setBackground( '.', feat( col, "bg white" ) + feat( col, "black" ) );
    for( unsigned int i = 0; i < 10; i++ )
    {
        canvas.clear();
        canvas.put( 0, 2, 'x' );
        canvas.put( i, 3, 'A', feat( col, "red" ) );
        canvas.put( 5, 0, 'B', feat( col, "blue" ) );
        canvas.put( 7, 8, 'Z', feat( col, "bg cyan" ) + feat( col, "black" ) + feat( sty, "bold" ) );
        canvas.refresh();
        this_thread::sleep_for( chrono::milliseconds( 100 ) );
    }

    cout << endl
         << "Canvas with an ASCII frame" << endl;

    Canvas ascii_framed_canvas( 15, 10 );
    ascii_framed_canvas.enableFrame( true );
    ascii_framed_canvas.setFrame( FrameStyle::ASCII, feat( col, "bg white" ) + feat( col, "black" ) );
    ascii_framed_canvas.clear();
    ascii_framed_canvas.put( 3, 4, 'H' );
    ascii_framed_canvas.put( 4, 4, 'e' );
    ascii_framed_canvas.put( 5, 4, 'l' );
    ascii_framed_canvas.put( 6, 4, 'l' );
    ascii_framed_canvas.put( 7, 4, 'o' );
    ascii_framed_canvas.refresh();

    sleep_for( seconds( 2 ) );

    cout << endl
         << "Canvas with a BOX frame" << endl;

    Canvas box_framed_canvas( 20, 8 );
    box_framed_canvas.enableFrame( true );
    box_framed_canvas.setFrame( FrameStyle::BOX );
    box_framed_canvas.clear();
    box_framed_canvas.put( 3, 4, 'H' );
    box_framed_canvas.put( 4, 4, 'e' );
    box_framed_canvas.put( 5, 4, 'l' );
    box_framed_canvas.put( 6, 4, 'l' );
    box_framed_canvas.put( 7, 4, 'o' );
    box_framed_canvas.refresh();

    sleep_for( seconds( 2 ) );

    cout << endl
         << "Plot2DCanvas with sin and cos" << endl;
    Plot2DCanvas plot_2d_canvas( 50, 20 );
    plot_2d_canvas.setBackground( ' ', feat( col, "bg white" ) );
    plot_2d_canvas.enableFrame( true );
    plot_2d_canvas.setFrame( FrameStyle::BOX, feat( col, "bg white" ) + feat( col, "black" ) );
    plot_2d_canvas.enableFrame( true );
    plot_2d_canvas.setFrame( FrameStyle::BOX, feat( col, "bg white" ) + feat( col, "black" ) );
    plot_2d_canvas.setScale( 1 / 3.14, 0.2 );
    for( float i = 0; i < 40; i++ )
    {
        plot_2d_canvas.setOffset( i / 3.14, -2 );
        plot_2d_canvas.clear();
        plot_2d_canvas.draw( std::function<float( float )>( []( float x ) -> float
                                                            { return std::cos( x ); } ),
                             'X',
                             feat( col, "bg white" ) + feat( col, "bd red" ) );
        plot_2d_canvas.draw( std::function<float( float )>( []( float x ) -> float
                                                            { return std::sin( x ); } ),
                             'X',
                             feat( col, "bg white" ) + feat( col, "bd blue" ) );
        plot_2d_canvas.refresh();
        sleep_for( milliseconds( 100 ) );
    }

    cout << endl
         << endl;
}

//====================================================
//     MAIN
//====================================================
int main()
{
    OPTION( CURSOR::OFF );

    // Manipulators:
    col_sty();      // Color/style.
    printer();      // For printing functions.

    // Progress bars:
    perc_bars();             // Percentage bar.
    load_bars();             // Loading bar.
    mixed_bars();            // Mixed bar.
    multi_bars();            // Multi progress bars
    progress_spinner();      // Progress spinner.

    // Terminal graphics visualization:
    canvas_2d();

    OPTION( CURSOR::ON );
}