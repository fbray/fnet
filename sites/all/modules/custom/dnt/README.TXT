The following describes the use of custom 'X-headers' to send do-not-translate instructions to t.com servers.

Hi Stephen,

Our developers have come back with a response. They don’t plan on creating functionality to support the 'translate'
attribute right now (I’ve proposed that they at least consider creating functionality for it since it may become an
HTML standard), but they’ve proposed a different solution which they’ve already begun development to support.

They’ve proposed that for each page that has custom meta content which should not be translated, you have the origin
server send a unique X-Header which the proxy will detect and comply with to not translate the meta content. This can
be used for things besides the meta tags too if you want to use it for any other custom translation integration.

The specs for the new X-Header:

X-Header variable name: X-OneLinkNoTx
X-Header value format: U;T;I;C;

Where “U;T;I;C;” should be customized to include URL, Tag, ID, and / or Class stack information declaring what should
not be translated. For the purpose of ensuring meta tags do not get translated, for each page with custom meta content,
you should send the X-Header with the value “U;/meta/;I;C;”. The proxy would then know to not translate the /meta/ tag
stack:

X-OneLinkNoTx = U;/meta/;I;C;

Will this solution work for your team?

*Be sure to only send this header to requests for pages which have custom meta tags. If you send this header and value
for all requests, the proxy will never translate any meta content.

The following info is probably more than you need, but I’d like to give you the full specs so you’re aware of what this
header will be capable of:

U;T;I;C; Specs:
U – URL pattern
	Matches any common string, not literal
	For example, “fiber” will match these URL patterns:
	/products/fiber-optic-cleaning-kits/product-description/
	/datacom-cabling/fiber-testing/fiber-oneshot-pro
	These would NOT match if you used “/fiber/” with beginning and trailing / forward slashes because the URL examples
	above do not have a trailing / forward slash after “/fiber”
	Supports Regular Expressions, but does not require RegEx (so you don’t need to escape ? question marks, $ dollar
	signs, etc.)
T – Tag Stack
	Only supports block-level tags
	Do not include /a/ , /span/ , /b/ , /strong/ , etc. tags
	Matches any common string, not literal
	Does NOT support Regular Expressions
	Does not require full stack beginning with /html/ - you can simply use “/div/” to apply the no-translate logic to
	all <div>’s on the page
I – ID Stack
	Only supports ID’s of block-level HTML tags
	Do not include ID’s from /a/ , /span/ , /b/ , /strong/ , etc. tags
	Matches any common string, not literal
	Does not support Regular Expressions
C – Class Stack
	Only supports Class stacks of block-level HTML tags
	Do not include classes from /a/ , /span/ , /b/ , /strong/ , etc. tags
	Matches any common string, not literal
	Does not support Regular Expressions

You can combine the stacks to be specific about sections of pages to apply the no-translate logic to. For example, if
you wanted to exclude the table in the Documents tab content from being translated on this page:
http://www.flukenetworks.com/products/fiber-optic-cleaning-kits
You could use a U;T;I;C; similar to:
/fiber-optic-cleaning-kits;/td/;/box_documents/;C;
Where “U” matches the URL string, “T” matches <td> HTML elements only, “I” matches the HTML element with the ID
“box_documents”, and “C” is not specified.

