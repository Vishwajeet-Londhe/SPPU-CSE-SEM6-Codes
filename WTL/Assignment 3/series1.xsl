<?xml version = "1.0" encoding = "UTF-8"?> 
<xsl:stylesheet version = "1.0" 
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">
   <xsl:template match = "/"> 
      <html> 
         <body> 
            <h2>WebSeries</h2> 
            <table border = "1"> 
               <tr bgcolor = "#9acd32"> 
                  <th>Id</th> 
                  <th>Name</th> 
                  <th>Creator</th> 
                  <th>Platform</th>
                  <th>Image</th>
               </tr> 
					
               <xsl:for-each select = "class/car"> 
				      <tr> 
                     <td><xsl:value-of select = "@id"/> </td> 
	                 <td><xsl:value-of select = "name"/></td> 
                     <td><xsl:value-of select = "creator"/></td> 
                     <td><xsl:value-of select = "platform"/></td> 
                  </tr> 
               </xsl:for-each> 
            </table> 
         </body> 
      </html> 
   </xsl:template>  
</xsl:stylesheet>
