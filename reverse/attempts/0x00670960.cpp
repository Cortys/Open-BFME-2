// ?Rva00804920Update@@YAPBDPAURva008042B0Http@@@Z
// partial score=0.9 date=2026-10-02
// BANKED NEAR MISS -- retail 0x00670960, extent 2669 bytes (row size 2669, not the
// donor-matched 2668: the body's last call is the security-cookie check at +2665
// whose 4-byte displacement ends at 2669).
//
// This is the tail of Code/Libraries/Source/DirtySock/Y2ProtoMangleHelpers.cpp
// exactly as it stood when the byte gate refused the row.  To reproduce, append it
// to that file (all its callees are declared there) and make the three context edits
// the block depends on:
//   1. Rva008042B0Http's tail fields m_pad120/128/12C/138/13C/140 -> the donor's
//      m_field120/128/12C/138/13C/140 (same layout, no byte effect);
//   2. Rva007FDB60SocketInfo's two declarations become `int` (not `void`): this body
//      compares its result against 0, and the int spelling needs its own pin
//      ?Rva007FDB60SocketInfo@@YAHPAXH0H@Z at 0x0066A030 alongside the void alias;
//   3. nothing else -- struct Rva00804920Connection and the two extern "C" callee
//      declarations travel inside this block.
//
// Verdict: 2583 of 2669 bytes already reproduce.  First difference +0x186
// (RVA 0x00670AE6) is the tail block's forward `jmp` displacement -- target
// e9 b6 08 00 00, compiled e9 ca 08 00 00, i.e. the compiled body carries ~0x14
// extra bytes before that tail, and the compiled symbol is 2734 bytes against the
// row's 2669.  The extra bytes are the shape of a stack-checked IAT call
// (`mov esi,esp` / pushes / `ff 15` / `cmp esi,esp` / `call __RTC_CheckEsp`) where
// retail makes a plain direct `e8` call: one callee in this body is reaching the CRT
// through its header declaration instead of the game's own address.  Find that call
// site (the one whose format-string push is 0x008585B8) and give it the game's own
// declaration -- the donor declares every callee it uses as a plain function.
// t=40min model=deepseek-flash
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// Rva00804920Update -- retail 0x00670960, 2668 bytes, uniquely placed here by
// the sweep from the BFME1 body at 0x00804920 (no other masked hit, fanout 1).
// The donor side is clean C++, not a lift: what travels is its source, and the
// field names below are ours renamed to match it (same layout throughout).  The
// two extern "C" declarations are the donor's: 0x00669A90 and 0x00669F20 carry
// their plain C names, so the calls must emit those and not a C++ spelling.
// ---------------------------------------------------------------------------

struct Rva00804920HttpView : Rva008042B0Http
{
	int          m_field148;        // +0x148 in the enclosing record
};


extern "C" int Rva007FD5C0( void *socket, const void *address, int length );
extern "C" int Rva007FDA50( void *socket, char *buffer, int length,
		int flags, void *from, int *fromLength );

struct Rva00804920Connection
{
	int m_pad000;
	int m_address;
	int ( __cdecl *m_update )( Rva00804920Connection *connection );
	int ( __cdecl *m_finish )( Rva00804920Connection *connection );
};

const char *Rva00804920Update( Rva008042B0Http *http )
{
	int result;
	char peeraddr[ 0x100 ];
	char data[ 0x10 ];
	char *cursor;
	char *end;
	unsigned int work;
	int length;

	if( http->m_state == 1 )
	{
		if( http->m_conn != 0 )
		{
			if( ( (Rva00804920Connection *)http->m_conn )->m_update(
					(Rva00804920Connection *)http->m_conn ) < 0 )
			{
				( (Rva00804920Connection *)http->m_conn )->m_finish(
						(Rva00804920Connection *)http->m_conn );
				http->m_conn = 0;
				http->m_state = 8;
				Rva007FE780Printf( "ProtoMangle: Addr countdown failed!\n" );
			}
			else if( ( (Rva00804920Connection *)http->m_conn )->m_update(
					(Rva00804920Connection *)http->m_conn ) > 0 )
			{
				http->m_field10C =
						( (Rva00804920Connection *)http->m_conn )->m_address;
				( (Rva00804920Connection *)http->m_conn )->m_finish(
						(Rva00804920Connection *)http->m_conn );
				http->m_conn = 0;
			}
		}
	}

	if( http->m_state == 1 && http->m_field10C != 0 )
		{
			Rva00804380CloseSocket( http );
			if( ( http->m_field144-- < 0 ) ? 1 : 0 )
			{
				http->m_state = 8;
				Rva007FE780Printf( "ProtoMangle: Addr countdown failed!\n" );
				return 0;
			}

			Rva007FE780Printf(
					"ProtoMangle: Attempting to connect (addr=%08x, port=%d)\n",
				http->m_field10C, http->m_port );
			http->m_socket = Rva007FD2D0SocketOpen( 2, 1, 0 );
			if( http->m_socket != 0 )
			{
				*(unsigned short *)( data + 0 ) = 2;
				*(unsigned short *)( data + 2 ) = 0;
				*(int *)( data + 4 ) = 0;
				*(int *)( data + 8 ) = 0;
				*(int *)( data + 12 ) = 0;

				work = http->m_field10C;
				data[ 7 ] = (char)work; work >>= 8;
				data[ 6 ] = (char)work; work >>= 8;
				data[ 5 ] = (char)work; work >>= 8;
				data[ 4 ] = (char)work;
				data[ 2 ] = (char)( http->m_port >> 8 );
				data[ 3 ] = (char)http->m_port;

				Rva007FD5C0( http->m_socket, data, 0x10 );
				http->m_field13C = 0;
				http->m_state = 2;
				( (Rva00804920HttpView *)http )->m_field148 =
						Rva007FEA00Tick() + 0x7530;
			}
		}

	if( http->m_state == 2 )
	{
		if( Rva007FDB60SocketInfo( http->m_socket, 'stat', 0, 0 ) > 0 )
			http->m_state = 3;
		else if( Rva007FEA00Tick() >
				( (Rva00804920HttpView *)http )->m_field148 )
			http->m_state = 1;
	}

	if( http->m_state == 3 )
	{
		length = strlen( http->m_buffer );
		result = Rva007FD920Send( http->m_socket, http->m_buffer, length,
				0, 0, 0 );
		http->m_state = 4;
	}

	if( http->m_state == 4 )
	{
		result = Rva007FDA50( http->m_socket, peeraddr, 1, 0, 0, 0 );
		if( result > 0 )
		{
			http->m_buffer[ 0 ] = peeraddr[ 0 ];
			http->m_field13C = 1;
			http->m_state = 5;
		}
		if( result < 0 )
		{
			http->m_state = 1;
			return 0;
		}
	}

	if( http->m_state == 5 )
	{
		result = http->m_bufferSize - http->m_field13C;
		result = Rva007FDA50( http->m_socket,
				http->m_buffer + http->m_field13C,
				result, 0, 0, 0 );
		if( result < 0 )
		{
			Rva007FE780Printf( "ProtoMangle: ST_HTTP_FAIL (err=%d)\n", result );
			http->m_state = 8;
			Rva00804380CloseSocket( http );
			return 0;
		}
		http->m_field13C += result;
	}

	if( http->m_state == 5 && http->m_field13C > 4 )
	{
		cursor = http->m_buffer;
		end = http->m_buffer + http->m_field13C - 3;
		while( cursor != end &&
				( cursor[ 0 ] != '\r' || cursor[ 1 ] != '\n'
				|| cursor[ 2 ] != '\r' || cursor[ 3 ] != '\n' ) )
			++cursor;
		if( cursor == end )
			return 0;

		http->m_field128 = cursor + 4 - http->m_buffer;
		cursor[ 3 ] = 0;
		cursor[ 2 ] = 0;
		Rva007FE780Printf( "ProtoMangle: Received HTTP header: %s\n",
				http->m_buffer );
		cursor = http->m_buffer;
		if( cursor[ 0 ] != 'H' || cursor[ 1 ] != 'T'
				|| cursor[ 2 ] != 'T' || cursor[ 3 ] != 'P' )
		{
			Rva007FE780Printf( "ProtoMangle: Bogus HTTP result!\n" );
			Rva00804380CloseSocket( http );
			http->m_state = 8;
			return 0;
		}

		while( *cursor != 0 && *cursor > ' ' )
			++cursor;
		while( *cursor != 0 && *cursor <= ' ' )
			++cursor;
		http->m_httpCode = 0;
		for( ; *cursor >= '0' && *cursor <= '9'; ++cursor )
		{
			http->m_httpCode = http->m_httpCode * 10
				+ ( *cursor & 0x0f );
		}

		http->m_field12C = -1;
		cursor = strstr( http->m_buffer, "\nContent-Length:" );
		if( cursor != 0 )
		{
			++cursor;
			for( ; *cursor >= ' '
					&& ( *cursor < '0' || *cursor > '9' ); ++cursor )
			{
			}
			http->m_field12C = 0;
			while( *cursor >= '0' && *cursor <= '9' )
			{
				http->m_field12C = http->m_field12C * 10
						+ ( *cursor & 0x0f );
				++cursor;
			}
		}

		http->m_field120 = 0;
		cursor = strstr( http->m_buffer, "\nConnection: close" );
		http->m_field124 = cursor != 0;
		http->m_buffer[ http->m_field128 - 2 ] = '\r';
		http->m_buffer[ http->m_field128 - 1 ] = '\n';

		if( http->m_field12C >= 0 &&
			http->m_field12C == http->m_field13C - http->m_field128 )
		{
			http->m_state = 7;
			http->m_field138 = http->m_field128;
			http->m_buffer[ http->m_field13C ] = 0;
			return http->m_buffer + http->m_field138;
		}
		http->m_state = 6;
		http->m_field140 = http->m_field13C - http->m_field128;
	}

	if( http->m_state == 6 )
	{
		result = http->m_bufferSize - http->m_field13C;
		if( result <= 0 )
			result = 0;
		else
			result = Rva007FDA50( http->m_socket,
					http->m_buffer + http->m_field13C, result, 0, 0, 0 );
		if( result == 0 )
			return 0;
		if( result == -1 && ( http->m_field12C == -1
				|| http->m_field12C == http->m_field140 ) )
		{
			http->m_field12C = http->m_field140;
			Rva007FE780Printf( "ProtoMangle: Trying to close\n" );
			Rva00804380CloseSocket( http );
			http->m_state = 7;
		}
		else if( result < 0 )
		{
			Rva007FE780Printf( "ProtoMangle: ST_FAIL (err=%d)\n", result );
			http->m_state = 8;
			Rva00804380CloseSocket( http );
		}
		else
		{
			http->m_field13C += result;
			http->m_field140 += result;
		}

		if( http->m_field12C >= 0 && http->m_field140 >= http->m_field12C )
		{
			Rva007FE780Printf( "Http: got body bytes (%d)\n", http->m_field12C );
			http->m_state = 7;
			http->m_buffer[ http->m_field13C ] = 0;
			return http->m_buffer + http->m_field138;
		}
	}

	return 0;
}
