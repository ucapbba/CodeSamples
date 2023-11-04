using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Identity.Web;

namespace MyFisrtAzureWebApp.Pages
{

    [AuthorizeForScopes(ScopeKeySection = "DownstreamApi:Scopes")]
    public class NewPageModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;

        private readonly IDownstreamWebApi _downstreamWebApi;

        public NewPageModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
        }

        public async Task OnGet()
        {
        }
    }
}